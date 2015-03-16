//
//  ViewController.swift
//  geotrigger-sample
//
//  Created by Ryan Arana on 3/4/15.
//  Copyright (c) 2015 geotrigger.esri.com. All rights reserved.
//

import UIKit
import CoreLocation
import GeotriggerSDK

class ViewController: UIViewController {
    @IBOutlet weak var managerReadyLabel: UILabel!
    @IBOutlet weak var registeredForPushNotificationsLabel: UILabel!
    @IBOutlet weak var triggerCreatedLabel: UILabel!
    @IBOutlet weak var triggerFiredLabel: UILabel!
    @IBOutlet weak var locationUpdateReceivedLabel: UILabel!
    @IBOutlet weak var locationUpdateSentLabel: UILabel!

    var triggerCreated = false
    var lastLocationReceived: CLLocation?

    override func viewDidLoad() {
        super.viewDidLoad()

        // The didReceiveLocationUpdates block is called every time the manager receive a CLLocation from the CLLocationManager.
        // You can use this block to get access to all location updates from the OS without implementing your own
        // CLLocationManagerDelegate. Here we use it to create a trigger around the first location we receive which will
        // fire on leaving the trigger region. On all subsequent location updates we update the UI to show the latest location
        // we've received.
        AGSGTGeotriggerManager.sharedManager().didReceiveLocationUpdates = { (locations: [AnyObject]!) in
            if let locations = locations as? [CLLocation] {
                self.lastLocationReceived = locations[0]
                self.locationUpdateReceivedLabel.text = NSString(format: "lat: %3.6f, long: %3.6f", locations[0].coordinate.latitude, locations[0].coordinate.longitude)
                self.managerReadyLabel.text = NSUserDefaults.standardUserDefaults().stringForKey("managerReadyText")

                if !self.triggerCreated {
                    self.triggerCreated = true

                    // Create a geotrigger builder object and set its properties as desired.
                    let builder = AGSGTTriggerBuilder()
                    builder.triggerId = "sampleTrigger"
                    builder.tags = [AGSGTGeotriggerManager.sharedManager().deviceDefaultTag]
                    builder.direction = "leave"
                    builder.setGeoWithLocation(self.lastLocationReceived, distance: 100)
                    builder.notificationText = "Trigger fired!"
                    let params = builder.build()
                    AGSGTApiClient.sharedClient().postPath("trigger/create", parameters: params,
                        success: { (res: AnyObject!) in
                            println("Trigger created: \(res)")
                            self.triggerCreatedLabel.text = "Yes"
                        },
                        failure: { (err: NSError!) in
                            println("Trigger create error: \(err.userInfo)")
                            self.triggerCreatedLabel.text = "Error"
                            self.triggerCreated = false
                        })
                }
            }
        }

        NSNotificationCenter.defaultCenter().addObserverForName("registerForRemoteNotificationsFailure", object: nil, queue: NSOperationQueue.mainQueue()) { (notification: NSNotification!) in
            self.registeredForPushNotificationsLabel.text = "Error"
        }

        NSNotificationCenter.defaultCenter().addObserverForName("registerForRemoteNotificationsSuccess", object: nil, queue: NSOperationQueue.mainQueue()) { (notification: NSNotification!) in
            self.registeredForPushNotificationsLabel.text = "Yes"
        }

        NSNotificationCenter.defaultCenter().addObserverForName("pushNotificationReceived", object: nil, queue: NSOperationQueue.mainQueue()) { (notification: NSNotification!) in
            self.triggerFiredLabel.text = "Yes"
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func deviceNotifyTapped() {
        AGSGTApiClient.sharedClient().postPath("device/notify",
            parameters:[ "text": "This came from device/notify", "url": "http://pdx.esri.com" ],
            success: { (res: AnyObject!) in
                println("device/notify success: \(res)")
            }, failure: { (error: NSError!) in
                println("device/notify failed: \(error.userInfo)")
            })
    }

}

