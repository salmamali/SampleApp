
#import "RNIbgxNetworkManager.h"
#import <React/RCTLog.h>

@implementation RNIbgxNetworkManager

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(get:(NSString *)string callback:(RCTResponseSenderBlock)callback)
{
    IBGxNetworkManager *networkManager = [[IBGxNetworkManager alloc] init];
    NSURL *url = [NSURL URLWithString:[string stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
    [networkManager GET:url parameters:nil completionHandler:^(id  _Nullable response, NSError * _Nullable error) {
        
        if (error == NULL) {
            callback(@[[NSNull null], response]);
        } else {
            callback(@[[error localizedDescription], [NSNull null]]);
        }
    }];
}

@end
  
