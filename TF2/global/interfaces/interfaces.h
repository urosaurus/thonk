#ifndef INTERFACES_H
#define INTERFACES_H
#ifdef _WIN32
#pragma once
#endif

namespace i
{

	// client
	extern ibaseclientdll*		client;
	extern icliententitylist*	entitylist;
	extern iclientmodeshared*	clientmode;

	// engine
	extern ivengineclient*		engineclient;
	extern ienginetrace*		enginetrace;
	extern ivdebugoverlay*		debugoverlay;
	extern ienginevgui*			enginevgui;
	extern ivefx*				efx;

	// public
	extern global_vars_base*	globals;

	// vgui
	extern ipanel*				panel;
	extern isurface*			surface;

}

#endif // !INTERFACES_H