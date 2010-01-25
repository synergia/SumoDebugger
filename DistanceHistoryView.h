//
//  DistanceHistoryView.h
//  SumoDebugger
//
//  Created by Tymon Tobolski on 10-01-25.
//  Copyright 2010 Politechnika Wrocławska. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface DistanceHistoryView : NSView {
	NSMutableArray *_data;
	NSMutableArray *_kalmanData;
	double P;
}

-(NSMutableArray *)data;
-(void)addValue:(int)value;

@end
