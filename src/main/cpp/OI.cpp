/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <Commands/IntakeRollThenDown.h>
#include <Commands/IntakeDown.h>
#include <Commands/Fire.h>
#include <Commands/IntakeUp.h>
#include <Commands/FireThenReset.h>
#include <Commands/IntakeDownAndRoll.h>
#include <Commands/CatapultReset.h>
#include <Commands/IntakeRoll.h>
#include <Commands/AutoTurn.h>
using namespace frc;
#include <map>
#include <string>

OI::OI(): joy(0) {

	JoystickButton* Button1 = new JoystickButton(&joy, 1);
	JoystickButton* Button2 = new JoystickButton(&joy, 2);
	JoystickButton* Button3 = new JoystickButton(&joy, 3);
	JoystickButton* Button4 = new JoystickButton(&joy, 4);
	JoystickButton* Button6 = new JoystickButton(&joy, 6);
	JoystickButton* Button7 = new JoystickButton(&joy, 7);

	Button1->WhenPressed(new FireThenReset());
	Button2->WhenPressed(new IntakeDownAndRoll());
	Button3->WhenPressed(new IntakeUp());
	Button4->WhenPressed(new IntakeRollThenDown());
	Button6->WhenPressed(new Fire());
	Button7->WhenPressed(new AutoTurn(1));
	// Process operator interface input here.

	std::map<std::string, JoystickButton*> button_map; // = { {"fire", { &joy, 1} } };
	char* names[] = {"fire", "down"};
	for (int i = 0; i < 2; ++i)
		button_map[names[i]] = new JoystickButton(&joy, i+1);
}
