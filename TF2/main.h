#ifndef MAIN_H
#define MAIN_H
#ifdef _WIN32
#pragma once
#endif

// dependencies
#include <Windows.h>
#include <assert.h>
#include <Psapi.h>
#include <string>
#include <memory>

// helpers
#include "helpers/util.h"
#include "helpers/vector.h"
#include "helpers/color.h"
#include "helpers/vmt.h"

// sdk
#include "sdk/sdk.h"

// global
#include "global/interfaces/interfaces.h"
#include "global/hooks/hooks.h"
#include "global/fonts/fonts.h"
#include "global/draw/draw.h"
#include "global/global.h"

// menu/vars
#include "menu/vars/vars.h"
#include "menu/menu.h"

// setup
#include "setup/setup.h"

#endif // !MAIN_H