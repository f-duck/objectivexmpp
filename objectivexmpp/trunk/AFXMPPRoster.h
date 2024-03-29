//
//  XMPPRoster.h
//  ObjectiveXMPP
//
//  Created by Keith Duncan on 05/01/2009.
//  Copyright 2009 thirty-three software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFKeyIndexedSet;
@protocol AFXMPPRosterContact;

@interface AFXMPPRoster : NSObject {
 @private
	NSNetServiceBrowser *_browser;
	
	AFKeyIndexedSet *_bonjourServices;
}

/*!
	@brief
	
 */
+ (AFXMPPRoster *)sharedRoster;

/*!
	@brief
	This should only be called once the local process service has been advertised so that it can be excluded.
	There exists the potential for a race condition, might want to reverse the order of registration/discovery so that we only accept incoming connections once the initial browse has been completed - we know when we've got all the current services when moreComing is NO.
 */
- (void)searchForBonjourServices;

/*!
	@brief
	
 */
@property (readonly, retain) AFKeyIndexedSet *bonjourServices;

@end
