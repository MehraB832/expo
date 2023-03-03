//  Copyright © 2021 650 Industries. All rights reserved.

#import <EXUpdates/EXUpdatesAppController.h>

@class EXUpdatesConfig;
@class EXUpdatesSelectionPolicy;
@protocol EXUpdatesAppLauncher;

NS_ASSUME_NONNULL_BEGIN

@interface EXUpdatesAppController (Internal)

@property (nonatomic, readonly) dispatch_queue_t controllerQueue;

- (BOOL)initializeUpdatesDirectoryWithError:(NSError ** _Nullable)error;
- (BOOL)initializeUpdatesDatabaseWithError:(NSError ** _Nullable)error;
- (void)purgeUpdatesLogsOlderThanOneDay;

- (void)setDefaultSelectionPolicy:(EXUpdatesSelectionPolicy *)selectionPolicy;
- (void)setLauncher:(nullable id<EXUpdatesAppLauncher>)launcher;
- (void)setConfigurationInternal:(EXUpdatesConfig *)configuration;
- (void)setIsStarted:(BOOL)isStarted;

- (void)runReaper;

@end

NS_ASSUME_NONNULL_END
