#include "../main.h"

bool __fastcall hk_create_move(iclientmodeshared* ecx, PVOID edx, float input_sample_time, user_cmd* cmd)
{

	static auto original_create_move = h::client_mode_hook->get_original_function< decltype(&hk_create_move) >(21);

	// acquire a pointer to our local player
	g::local = reinterpret_cast<c_baseentity*>(i::entitylist->get_client_entity(i::engineclient->get_local_player()));

	// set up a global usercmd pointer
	g::cmd = cmd;

	// acquire a pointer to bsendpacket
	uintptr_t _bp; __asm mov _bp, ebp;
	bool* send_packet = (bool*)(***(uintptr_t***)_bp - 1);

	if (g::local != nullptr || cmd != nullptr) {
		// empty
	}

	return original_create_move(ecx, edx, input_sample_time, cmd);

}

float __fastcall hk_get_viewmodel_fov(iclientmodeshared* ecx, PVOID edx)
{

	static auto original_get_viewmodel_fov = h::client_mode_hook->get_original_function< decltype(&hk_get_viewmodel_fov) >(32);

	// empty

	return original_get_viewmodel_fov(ecx, edx);

}

int __fastcall hk_key_event(ibaseclientdll* ecx, PVOID edx, int event_code, int key_num, const char* current_binding)
{

	static auto original_key_event = h::client_hook->get_original_function< decltype(&hk_key_event) >(20);

	if (event_code == 1) {
		menu::handle_input(key_num);
	}

	return original_key_event(ecx, edx, event_code, key_num, current_binding);

}

void __fastcall hk_paint_traverse(ipanel* ecx, PVOID edx, unsigned int vgui_panel, bool force_repaint, bool allow_force)
{

	static auto original_paint_traverse = h::panel_hook->get_original_function< decltype(&hk_paint_traverse) >(41);
	original_paint_traverse(ecx, edx, vgui_panel, force_repaint, allow_force);

	static bool init = true;

	if (init) {

		f::arial = i::surface->create_font();
		i::surface->set_font_glyph_set(f::arial, "Arial", 15, 0, 0, 0, FONTFLAG_OUTLINE);

		f::verdana = i::surface->create_font();
		i::surface->set_font_glyph_set(f::verdana, "Verdana", 14, 400, 0, 0, FONTFLAG_DROPSHADOW);

		init = false;

	}

	if (vgui_panel == i::enginevgui->get_panel(PANEL_CLIENTDLL)) {
		
		if (vars::menu::menu_active) {
			menu::insert_menu_items();
			menu::draw_menu();
		}

	}

}

namespace s
{

	void setup_interfaces()
	{

		create_interface_fn client	= reinterpret_cast<create_interface_fn>(GetProcAddress(GetModuleHandleA("client.dll"), "CreateInterface"));
		create_interface_fn engine	= reinterpret_cast<create_interface_fn>(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"));
		create_interface_fn vgui	= reinterpret_cast<create_interface_fn>(GetProcAddress(GetModuleHandleA("vgui2.dll"), "CreateInterface"));
		create_interface_fn mat		= reinterpret_cast<create_interface_fn>(GetProcAddress(GetModuleHandleA("vguimatsurface.dll"), "CreateInterface"));

		// client
		i::client		= static_cast<ibaseclientdll*>(client("VClient017", nullptr));
		i::entitylist	= static_cast<icliententitylist*>(client("VClientEntityList003", nullptr));
		i::clientmode	= **(iclientmodeshared***)((*(DWORD**)i::client)[10] + 0x5);

		// engine
		i::engineclient	= static_cast<ivengineclient*>(engine("VEngineClient013", nullptr));
		i::enginetrace	= static_cast<ienginetrace*>(engine("EngineTraceClient003", nullptr));
		i::debugoverlay = static_cast<ivdebugoverlay*>(engine("VDebugOverlay003", nullptr));
		i::enginevgui	= static_cast<ienginevgui*>(engine("VEngineVGui001", nullptr));
		i::efx			= static_cast<ivefx*>(engine("VEngineEffects001", nullptr));

		// public
		i::globals		= *reinterpret_cast<global_vars_base**>(u::find_signature("engine.dll", "A1 ? ? ? ? 8B 11 68") + 8);

		// vgui
		i::surface		= static_cast<isurface*>(mat("VGUI_Surface030", nullptr));
		i::panel		= static_cast<ipanel*>(vgui("VGUI_Panel009", nullptr));

	}

	void setup_hooks()
	{

		if (i::clientmode != nullptr) {

			h::client_mode_hook = std::make_unique<vmt_manager>(i::clientmode);

			h::client_mode_hook->hook_function(reinterpret_cast<bool*>(hk_create_move), 21);
			h::client_mode_hook->hook_function(reinterpret_cast<float*>(hk_get_viewmodel_fov), 32);

		}

		if (i::client != nullptr) {
			h::client_hook = std::make_unique<vmt_manager>(i::client);
			h::client_hook->hook_function(reinterpret_cast<int*>(hk_key_event), 20);
		}

		if (i::panel != nullptr) {
			h::panel_hook = std::make_unique<vmt_manager>(i::panel);
			h::panel_hook->hook_function(reinterpret_cast<void*>(hk_paint_traverse), 41);
		}

	}

	bool ready_to_blast()
	{

		if (i::client == nullptr)
			return true;

		return false;

	}

}