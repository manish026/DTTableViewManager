//
//  DTTableViewDataStorage.h
//  DTTableViewManager
//
//  Created by Denys Telezhkin on 24.11.13.
//  Copyright (c) 2013 Denys Telezhkin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTTableViewUpdate.h"



@protocol DTTableViewDataStorageUpdating

-(void)performUpdate:(DTTableViewUpdate *)update;

@optional

-(void)performAnimation:(void(^)(UITableView *))animationBlock;

@end



@protocol DTTableViewDataStorage <NSObject>

/**
 Returns array of sections, conforming to DTTableViewSectionModel protocol.
 */

-(NSArray*)sections;

@property (nonatomic, weak) id <DTTableViewDataStorageUpdating> delegate;

@optional

-(instancetype)searchingStorageForSearchString:(NSString *)searchString
                                 inSearchScope:(NSInteger)searchScope;

- (id)headerModelAtIndex:(NSInteger)index;
- (id)footerModelAtIndex:(NSInteger)index;

@end