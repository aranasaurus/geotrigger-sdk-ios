//
//  AppDelegate.swift
//  geotrigger-sample
//
//  Created by Ryan Arana on 3/4/15.
//  Copyright (c) 2015 geotrigger.esri.com. All rights reserved.
//

import UIKit
import GeotriggerSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {

        NSUserDefaults.standardUserDefaults().setObject("No - not setup yet", forKey: "managerReadyText")

        // Enable debug logs to the console. This spits out a lot of logs so you probably don't want to do this in a release
        // build, but it is good for helping track down any problems you may encounter.
        AGSGTGeotriggerManager.setLogLevel(AGSGTLogLevel.Debug)


        // Set up the manager singleton with your clientId and any tracking profile you pass in here
        // will be used to start the manager when it is ready. You can also pass in UIRemoteNotificationTypes
        // to have the manager register your application for with Apple when it is ready to receive an APNS
        // device token. Note, you'll have to implement application:didRegisterForRemoteNotificationsWithDeviceToken:
        // in your UIApplicationDelegate. The readyBlock will be run once the manager is ready to send updates
        // to the server.
        AGSGTGeotriggerManager.setupWithClientId("Your client ID here", isProduction: false) { (err: NSError?) in
            AGSGTGeotriggerManager.sharedManager().trackingProfile = AGSGTTrackingProfile.Adaptive.rawValue
            var managerReadyText = "Yes"
            if let err = err {
                managerReadyText = "No - error!"
            }
            NSUserDefaults.standardUserDefaults().setObject(managerReadyText, forKey: "managerReadyText")
        }

        // If we were launched from a push notification, send the payload to the Geotrigger Manager
        if let remoteNotification = launchOptions?[UIApplicationLaunchOptionsRemoteNotificationKey] as? [String:AnyObject] {
            AGSGTGeotriggerManager.handlePushNotification(remoteNotification, showAlert:false)
        }

        // Override point for customization after application launch.
        return true
    }

    func application(application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: NSError) {
        println("Failed to register for remote notifications with Apple: \(error.debugDescription)")
        NSNotificationCenter.defaultCenter().postNotificationName("registerForRemoteNotificationsFailure", object: nil)
    }

    func application(application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: NSData) {
        NSNotificationCenter.defaultCenter().postNotificationName("registerForRemoteNotificationsSuccess", object: nil)
    }

    func application(application: UIApplication, didReceiveRemoteNotification userInfo: [NSObject : AnyObject]) {
        if let aps = userInfo["aps"] as? [String:AnyObject] {
            if let message = aps["alert"] as? String {
                if message == "Trigger fired!" {
                    NSNotificationCenter.defaultCenter().postNotificationName("pushNotificationReceived", object: nil)
                }
            }
        }
    }

}

