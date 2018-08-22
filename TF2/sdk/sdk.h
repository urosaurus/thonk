#ifndef SDK_H
#define SDK_H
#ifdef _WIN32
#pragma once
#endif

// forward declarations
class client_networkable;
class client_renderable;
class client_unknown;
class client_entity;
class base_handle;
class game_trace;

// type definitions
typedef PVOID(*create_interface_fn)(const char* name, int* return_code);
typedef float matrix3x4_t[3][4];
typedef game_trace trace_t;

#pragma region includes

// client
#include "client/ibaseclientdll.h"
#include "client/icliententitylist.h"
#include "client/iclientmodeshared.h"
#include "client/c_baseentity.h"
#include "client/user_cmd.h"

// engine
#include "engine/ivengineclient.h"
#include "engine/ivdebugoverlay.h"
#include "engine/ienginetrace.h"
#include "engine/ienginevgui.h"
#include "engine/iefx.h"

// public
#include "public/global_vars_base.h"

// vgui
#include "vgui/isurface.h"
#include "vgui/ipanel.h"

#pragma endregion

#endif // !SDK_H