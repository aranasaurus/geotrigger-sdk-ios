// Namespaced Header

#ifndef __NS_SYMBOL
// We need to have multiple levels of macros here so that __NAMESPACE_PREFIX_ is
// properly replaced by the time we concatenate the namespace prefix.
#define __NS_REWRITE(ns, symbol) ns ## _ ## symbol
#define __NS_BRIDGE(ns, symbol) __NS_REWRITE(ns, symbol)
#define __NS_SYMBOL(symbol) __NS_BRIDGE(AGSGT, symbol)
#endif

#ifndef ddLogLevel
#define ddLogLevel __NS_SYMBOL(ddLogLevel)
#endif

// Classes
#ifndef AFHTTPBodyPart
#define AFHTTPBodyPart __NS_SYMBOL(AFHTTPBodyPart)
#endif

#ifndef AFHTTPClient
#define AFHTTPClient __NS_SYMBOL(AFHTTPClient)
#endif

#ifndef AFHTTPRequestOperation
#define AFHTTPRequestOperation __NS_SYMBOL(AFHTTPRequestOperation)
#endif

#ifndef AFJSONRequestOperation
#define AFJSONRequestOperation __NS_SYMBOL(AFJSONRequestOperation)
#endif

#ifndef AFMultipartBodyStream
#define AFMultipartBodyStream __NS_SYMBOL(AFMultipartBodyStream)
#endif

#ifndef AFNetworkActivityIndicatorManager
#define AFNetworkActivityIndicatorManager __NS_SYMBOL(AFNetworkActivityIndicatorManager)
#endif

#ifndef AFQueryStringPair
#define AFQueryStringPair __NS_SYMBOL(AFQueryStringPair)
#endif

#ifndef AFStreamingMultipartFormData
#define AFStreamingMultipartFormData __NS_SYMBOL(AFStreamingMultipartFormData)
#endif

#ifndef AFURLConnectionOperation
#define AFURLConnectionOperation __NS_SYMBOL(AFURLConnectionOperation)
#endif

#ifndef DDASLLogCapture
#define DDASLLogCapture __NS_SYMBOL(DDASLLogCapture)
#endif

#ifndef DDASLLogger
#define DDASLLogger __NS_SYMBOL(DDASLLogger)
#endif

#ifndef DDAbstractLogger
#define DDAbstractLogger __NS_SYMBOL(DDAbstractLogger)
#endif

#ifndef DDFileLogger
#define DDFileLogger __NS_SYMBOL(DDFileLogger)
#endif

#ifndef DDLog
#define DDLog __NS_SYMBOL(DDLog)
#endif

#ifndef DDLogFileFormatterDefault
#define DDLogFileFormatterDefault __NS_SYMBOL(DDLogFileFormatterDefault)
#endif

#ifndef DDLogFileInfo
#define DDLogFileInfo __NS_SYMBOL(DDLogFileInfo)
#endif

#ifndef DDLogFileManagerDefault
#define DDLogFileManagerDefault __NS_SYMBOL(DDLogFileManagerDefault)
#endif

#ifndef DDLogMessage
#define DDLogMessage __NS_SYMBOL(DDLogMessage)
#endif

#ifndef DDLoggerNode
#define DDLoggerNode __NS_SYMBOL(DDLoggerNode)
#endif

#ifndef DDTTYLogger
#define DDTTYLogger __NS_SYMBOL(DDTTYLogger)
#endif

#ifndef DDTTYLoggerColorProfile
#define DDTTYLoggerColorProfile __NS_SYMBOL(DDTTYLoggerColorProfile)
#endif

// Functions
#ifndef AFContentTypesFromHTTPHeader
#define AFContentTypesFromHTTPHeader __NS_SYMBOL(AFContentTypesFromHTTPHeader)
#endif

#ifndef AFContentTypesFromHTTPHeader
#define AFContentTypesFromHTTPHeader __NS_SYMBOL(AFContentTypesFromHTTPHeader)
#endif

#ifndef AFQueryStringFromParametersWithEncoding
#define AFQueryStringFromParametersWithEncoding __NS_SYMBOL(AFQueryStringFromParametersWithEncoding)
#endif

#ifndef AFQueryStringPairsFromDictionary
#define AFQueryStringPairsFromDictionary __NS_SYMBOL(AFQueryStringPairsFromDictionary)
#endif

#ifndef AFQueryStringPairsFromKeyAndValue
#define AFQueryStringPairsFromKeyAndValue __NS_SYMBOL(AFQueryStringPairsFromKeyAndValue)
#endif

#ifndef doesAppRunInBackground
#define doesAppRunInBackground __NS_SYMBOL(doesAppRunInBackground)
#endif

#ifndef DDExtractFileNameWithoutExtension
#define DDExtractFileNameWithoutExtension __NS_SYMBOL(DDExtractFileNameWithoutExtension)
#endif

#ifndef AFQueryStringFromParametersWithEncoding
#define AFQueryStringFromParametersWithEncoding __NS_SYMBOL(AFQueryStringFromParametersWithEncoding)
#endif

#ifndef AFQueryStringPairsFromDictionary
#define AFQueryStringPairsFromDictionary __NS_SYMBOL(AFQueryStringPairsFromDictionary)
#endif

#ifndef AFQueryStringPairsFromKeyAndValue
#define AFQueryStringPairsFromKeyAndValue __NS_SYMBOL(AFQueryStringPairsFromKeyAndValue)
#endif

#ifndef DDExtractFileNameWithoutExtension
#define DDExtractFileNameWithoutExtension __NS_SYMBOL(DDExtractFileNameWithoutExtension)
#endif

#ifndef doesAppRunInBackground
#define doesAppRunInBackground __NS_SYMBOL(doesAppRunInBackground)
#endif

// Externs
#ifndef AFNetworkingErrorDomain
#define AFNetworkingErrorDomain __NS_SYMBOL(AFNetworkingErrorDomain)
#endif

#ifndef AFNetworkingOperationFailingURLRequestErrorKey
#define AFNetworkingOperationFailingURLRequestErrorKey __NS_SYMBOL(AFNetworkingOperationFailingURLRequestErrorKey)
#endif

#ifndef AFNetworkingOperationFailingURLResponseErrorKey
#define AFNetworkingOperationFailingURLResponseErrorKey __NS_SYMBOL(AFNetworkingOperationFailingURLResponseErrorKey)
#endif

#ifndef AFNetworkingOperationDidStartNotification
#define AFNetworkingOperationDidStartNotification __NS_SYMBOL(AFNetworkingOperationDidStartNotification)
#endif

#ifndef AFNetworkingOperationDidFinishNotification
#define AFNetworkingOperationDidFinishNotification __NS_SYMBOL(AFNetworkingOperationDidFinishNotification)
#endif

#ifndef AFNetworkingReachabilityDidChangeNotification
#define AFNetworkingReachabilityDidChangeNotification __NS_SYMBOL(AFNetworkingReachabilityDidChangeNotification)
#endif

#ifndef AFNetworkingReachabilityNotificationStatusItem
#define AFNetworkingReachabilityNotificationStatusItem __NS_SYMBOL(AFNetworkingReachabilityNotificationStatusItem)
#endif

#ifndef kAFUploadStream3GSuggestedPacketSize
#define kAFUploadStream3GSuggestedPacketSize __NS_SYMBOL(kAFUploadStream3GSuggestedPacketSize)
#endif

#ifndef kAFUploadStream3GSuggestedDelay
#define kAFUploadStream3GSuggestedDelay __NS_SYMBOL(kAFUploadStream3GSuggestedDelay)
#endif

#ifndef AFNetworkingReachabilityDidChangeNotification
#define AFNetworkingReachabilityDidChangeNotification __NS_SYMBOL(AFNetworkingReachabilityDidChangeNotification)
#endif

#ifndef AFNetworkingReachabilityNotificationStatusItem
#define AFNetworkingReachabilityNotificationStatusItem __NS_SYMBOL(AFNetworkingReachabilityNotificationStatusItem)
#endif

#ifndef AFNetworkingErrorDomain
#define AFNetworkingErrorDomain __NS_SYMBOL(AFNetworkingErrorDomain)
#endif

#ifndef AFNetworkingOperationFailingURLRequestErrorKey
#define AFNetworkingOperationFailingURLRequestErrorKey __NS_SYMBOL(AFNetworkingOperationFailingURLRequestErrorKey)
#endif

#ifndef AFNetworkingOperationFailingURLResponseErrorKey
#define AFNetworkingOperationFailingURLResponseErrorKey __NS_SYMBOL(AFNetworkingOperationFailingURLResponseErrorKey)
#endif

#ifndef AFNetworkingOperationDidStartNotification
#define AFNetworkingOperationDidStartNotification __NS_SYMBOL(AFNetworkingOperationDidStartNotification)
#endif

#ifndef AFNetworkingOperationDidFinishNotification
#define AFNetworkingOperationDidFinishNotification __NS_SYMBOL(AFNetworkingOperationDidFinishNotification)
#endif

#ifndef kAFUploadStream3GSuggestedPacketSize
#define kAFUploadStream3GSuggestedPacketSize __NS_SYMBOL(kAFUploadStream3GSuggestedPacketSize)
#endif

#ifndef kAFUploadStream3GSuggestedDelay
#define kAFUploadStream3GSuggestedDelay __NS_SYMBOL(kAFUploadStream3GSuggestedDelay)
#endif

