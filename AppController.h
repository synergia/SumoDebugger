//
//  AppController.h
//  SumoDebugger
//
//  Created by Tymon Tobolski on 10-01-16.
//  Copyright 2010 Politechnika Wrocławska. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "AmSerialPort.h"

#define GROUND_COUNT 4
#define DISTANCE_COUNT 6
#define ENGINE_COUNT 2

struct GroundSensor {
	NSButton *displayCheckBox;
	NSButton *activeCheckBox;
};

struct DistanceSensor {
	NSTextField *label;
	NSLevelIndicator *levelIndicator;
	NSButton *activeCheckBox;
};

struct Engine {
	NSSlider *slider;
	NSTextField *label;
};


@interface AppController : NSObject {
	NSUserDefaults *preferences;
	AMSerialPort *port;
	Boolean manualEngineMode;
	
	
	IBOutlet NSPopUpButton *portListPopUpButton;
	IBOutlet NSTextView *outputTextView;
	IBOutlet NSTextView *debugTextView;
	IBOutlet NSMatrix *selectEngineModeMatrix;
	IBOutlet NSTextField *customSendTextField;
	
	// ground sensors
	IBOutlet NSButton *ground0DisplayCheckBox;
	IBOutlet NSButton *ground1DisplayCheckBox;
	IBOutlet NSButton *ground2DisplayCheckBox;
	IBOutlet NSButton *ground3DisplayCheckBox;
	IBOutlet NSButton *ground0ActiveCheckBox;
	IBOutlet NSButton *ground1ActiveCheckBox;
	IBOutlet NSButton *ground2ActiveCheckBox;
	IBOutlet NSButton *ground3ActiveCheckBox;
	struct GroundSensor groundSensors[GROUND_COUNT];
	
	
	// distance sensors	
	IBOutlet NSTextField *dist0ValueLabel;
	IBOutlet NSTextField *dist1ValueLabel;
	IBOutlet NSTextField *dist2ValueLabel;
	IBOutlet NSTextField *dist3ValueLabel;
	IBOutlet NSTextField *dist4ValueLabel;
	IBOutlet NSTextField *dist5ValueLabel;
	IBOutlet NSLevelIndicator *dist0LevelIndicator;
	IBOutlet NSLevelIndicator *dist1LevelIndicator;
	IBOutlet NSLevelIndicator *dist2LevelIndicator;
	IBOutlet NSLevelIndicator *dist3LevelIndicator;
	IBOutlet NSLevelIndicator *dist4LevelIndicator;
	IBOutlet NSLevelIndicator *dist5LevelIndicator;
	IBOutlet NSButton *dist0ActiveCheckBox;
	IBOutlet NSButton *dist1ActiveCheckBox;
	IBOutlet NSButton *dist2ActiveCheckBox;
	IBOutlet NSButton *dist3ActiveCheckBox;
	IBOutlet NSButton *dist4ActiveCheckBox;
	IBOutlet NSButton *dist5ActiveCheckBox;
	struct DistanceSensor distanceSensors[DISTANCE_COUNT];
	
	
	// engines
	IBOutlet NSSlider *engine0Slider;
	IBOutlet NSSlider *engine1Slider;
	IBOutlet NSTextField *engine0ValueLabel;
	IBOutlet NSTextField *engine1ValueLabel;
	struct Engine engines[ENGINE_COUNT];
}

-(IBAction) startStopReading:(id)sender;
-(IBAction) selectPort:(id)sender;
-(IBAction) selectEngineMode:(id)sender;
-(IBAction) sendStart:(id)sender;
-(IBAction) sendReset:(id)sender;
-(IBAction) sendNewline:(id)sender;
-(IBAction) sendCustom:(id)sender;
-(IBAction) clearLog:(id)sender;

					   
-(void) updatePortList;
-(void) closePort;
-(void) parseInput:(NSString *)text;

-(void)log:(NSString *)text;

@end
