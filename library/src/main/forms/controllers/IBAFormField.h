//
// Copyright 2010 Itty Bitty Apps Pty Ltd
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this 
// file except in compliance with the License. You may obtain a copy of the License at 
// 
// http://www.apache.org/licenses/LICENSE-2.0 
// 
// Unless required by applicable law or agreed to in writing, software distributed under
// the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF 
// ANY KIND, either express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import <Foundation/Foundation.h>
#import "IBAFormFieldCell.h"
#import "IBAFormModelManager.h"
#import "IBACommon.h"

@protocol IBAFormFieldDelegate;

@interface IBAFormField : NSObject {
	NSString *key;
	NSString *title;
	BOOL editable;
	BOOL movable;
	id<IBAFormModelManager> modelManager;
	id<IBAFormFieldDelegate> delegate;
	IBAFormFieldStyle *formFieldStyle;
	BOOL nullable;
}

@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic, assign) BOOL movable;
@property (nonatomic, readonly) IBAFormFieldCell *cell;
@property (nonatomic, retain) id<IBAFormModelManager> modelManager;
@property (nonatomic, assign) id<IBAFormFieldDelegate> delegate;
@property (nonatomic, retain) IBAFormFieldStyle *formFieldStyle;
@property (nonatomic, assign, getter=isNullable) BOOL nullable;


- (id)initWithKey:(NSString*)key 
			title:(NSString*)title 
		 editable:(BOOL)editable 
		  movable:(BOOL)movable;

- (id)initWithKey:(NSString*)key 
			title:(NSString*)title;

- (void)updateCellContents;

#pragma mark -
#pragma mark Detail View Controller management
- (BOOL)hasDetailViewController;
- (UIViewController *)detailViewController;

#pragma mark -
#pragma mark Getting and setting the form field value
- (id)formFieldValue;
- (NSString *)formFieldStringValue;
- (BOOL)setFormFieldValue:(id)formVieldValue;

#pragma mark -
#pragma mark Selection notification
- (void)select;

@end


@protocol IBAFormFieldDelegate <NSObject>
@optional
- (BOOL)formField:(IBAFormField *)formField willSetValue:(id)value;
- (void)formField:(IBAFormField *)formField didSetValue:(id)value;
@end