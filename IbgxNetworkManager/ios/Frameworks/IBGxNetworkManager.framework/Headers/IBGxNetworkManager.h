//
//  IBGxNetworkManager.h
//  IBGxNetworkManager
//
//  Created by Hesham Abd-Elmegid on 7/10/16.
//  Copyright © 2016 Instabug. All rights reserved.
//

@import Foundation;

@interface IBGxNetworkManager : NSObject

/**
 *  When set to YES, all currently enqueued operations will continue running when
 app moves to the background state.
 */
@property (nonatomic, assign) BOOL shouldContinueRunningRequestsInBackground;

/**
 * Returns the shared singleton instance of the `IBGxNetworkManager` class.
 */
+ (nonnull instancetype)sharedInstance;

/**
 *  Enqueues a `GET` request and returns an `NSURLRequest` that represents it.
 *
 *  @param url               The URL being requested.
 *  @param parameters        A dictionary of parameters to be encoded and added to the request.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 *
 *  @return An `NSURLRequest` object that represents the request being enqueued.
 */
- (nonnull NSURLRequest *)GET:(nonnull NSURL *)url
                    parameters:(nullable NSDictionary *)parameters
             completionHandler:(nonnull void (^)(id _Nullable response, NSError * _Nullable error))completionHandler;

/**
 *  Enqueues a `POST` request and returns an `NSURLRequest` that represents it.
 *  The response will automatically be deserialized as a JSON object.
 *
 *  @param url               The URL being requested.
 *  @param parameters        A dictionary of parameters to be encoded and added to the request.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 *
 *  @return An `NSURLRequest` object that represents the request being enqueued.
 */
- (nonnull NSURLRequest *)POST:(nonnull NSURL *)url
                     parameters:(nullable NSDictionary *)parameters
             completionHandler:(nonnull void (^)(id _Nullable response, NSError * _Nullable error))completionHandler;

/**
 *  Enqueues a `DELETE` request and returns an `NSURLRequest` that represents it.
 *  The response will automatically be deserialized as a JSON object.
 *
 *  @param url               The URL being requested.
 *  @param parameters        A dictionary of parameters to be encoded and added to the request.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 *
 *  @return An `NSURLRequest` object that represents the request being enqueued.
 */
- (nonnull NSURLRequest *)DELETE:(nonnull NSURL *)url
                      parameters:(nullable NSDictionary *)parameters
               completionHandler:(nonnull void (^)(id _Nullable response, NSError * _Nullable error))completionHandler;

/**
 *  Enqueues a `PATCH` request and returns an `NSURLRequest` that represents it.
 *  The response will automatically be deserialized as a JSON object.
 *
 *  @param url               The URL being requested.
 *  @param parameters        A dictionary of parameters to be encoded and added to the request.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 *
 *  @return An `NSURLRequest` object that represents the request being enqueued.
 */
- (nonnull NSURLRequest *)PATCH:(nonnull NSURL *)url
                      parameters:(nullable NSDictionary *)parameters
              completionHandler:(nonnull void (^)(id _Nullable response, NSError * _Nullable error))completionHandler;

/**
 *  Enqueues a `PUT` request and returns an `NSURLRequest` that represents it.
 *  The response will automatically be deserialized as a JSON object.
 *
 *  @param url               The URL being requested.
 *  @param parameters        A dictionary of parameters to be encoded and added to the request.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 *
 *  @return An `NSURLRequest` object that represents the request being enqueued.
 */
- (nonnull NSURLRequest *)PUT:(nonnull NSURL *)url
                    parameters:(nullable NSDictionary *)parameters
            completionHandler:(nonnull void (^)(id _Nullable response, NSError * _Nullable error))completionHandler;

/**
 *  Enqueues a `HEAD` request and returns an `NSURLRequest` that represents it.
 *  The response will automatically be deserialized as a JSON object.
 *
 *  @param url               The URL being requested.
 *  @param parameters        A dictionary of parameters to be encoded and added to the request.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 *
 *  @return An `NSURLRequest` object that represents the request being enqueued.
 */
- (nonnull NSURLRequest *)HEAD:(nonnull NSURL *)url
                     parameters:(nullable NSDictionary *)parameters
             completionHandler:(nonnull void (^)(id _Nullable response, NSError * _Nullable error))completionHandler;

/**
 *  Enqueues a `GET` request that downloads data of an image.
 *  The response will automatically be deserialized as a JSON object.
 *
 *  @param url               The URL of the image being downloaded.
 *  @param completionHandler A block that will be executed when request finishes loaded or fails to load.
 */
- (void)downloadImageDataAtURL:(nonnull NSURL *)url
             completionHandler:(nonnull void (^)(NSData * _Nullable data, NSError * _Nullable error))completionHandler;
@end
