#ifndef C_BASEENTITY_H
#define C_BASEENTITY_H
#ifdef _WIN32
#pragma once
#endif

enum tf_cond
{
	TFCond_Slowed					= (1 << 0),		// Toggled when a player is slowed down. 
	TFCond_Zoomed					= (1 << 1),		// Toggled when a player is zoomed. 
	TFCond_Disguising				= (1 << 2),		// Toggled when a Spy is disguising.  
	TFCond_Disguised				= (1 << 3),		// Toggled when a Spy is disguised. 
	TFCond_Cloaked					= (1 << 4),		// Toggled when a Spy is invisible. 
	TFCond_Ubercharged				= (1 << 5),		// Toggled when a player is ÜberCharged. 
	TFCond_TeleportedGlow			= (1 << 6),		// Toggled when someone leaves a teleporter and has glow beneath their feet. 
	TFCond_Taunting					= (1 << 7),		// Toggled when a player is taunting. 
	TFCond_UberchargeFading			= (1 << 8),		// Toggled when the ÜberCharge is fading. 
	TFCond_CloakFlicker				= (1 << 9),		// Toggled when a Spy is visible during cloak. 
	TFCond_Teleporting				= (1 << 10),	// Only activates for a brief second when the player is being teleported; not very useful. 
	TFCond_Kritzkrieged				= (1 << 11),	// Toggled when a player is being crit buffed by the KritzKrieg. 
	TFCond_TmpDamageBonus			= (1 << 12),	// Unknown what this is for. Name taken from the AlliedModders SDK. 
	TFCond_DeadRingered				= (1 << 13),	// Toggled when a player is taking reduced damage from the Deadringer. 
	TFCond_Bonked					= (1 << 14),	// Toggled when a player is under the effects of The Bonk! Atomic Punch. 
	TFCond_Stunned					= (1 << 15),	// Toggled when a player's speed is reduced from airblast or a Sandman ball. 
	TFCond_Buffed					= (1 << 16),	// Toggled when a player is within range of an activated Buff Banner. 
	TFCond_Charging					= (1 << 17),	// Toggled when a Demoman charges with the shield. 
	TFCond_DemoBuff					= (1 << 18),	// Toggled when a Demoman has heads from the Eyelander. 
	TFCond_CritCola					= (1 << 19),	// Toggled when the player is under the effect of The Crit-a-Cola. 
	TFCond_InHealRadius				= (1 << 20),	// Unused condition, name taken from AlliedModders SDK. 
	TFCond_Healing					= (1 << 21),	// Toggled when someone is being healed by a medic or a dispenser. 
	TFCond_OnFire					= (1 << 22),	// Toggled when a player is on fire. 
	TFCond_Overhealed				= (1 << 23),	// Toggled when a player has >100% health. 
	TFCond_Jarated					= (1 << 24),	// Toggled when a player is hit with a Sniper's Jarate. 
	TFCond_Bleeding					= (1 << 25),	// Toggled when a player is taking bleeding damage. 
	TFCond_DefenseBuffed			= (1 << 26),	// Toggled when a player is within range of an activated Battalion's Backup. 
	TFCond_Milked					= (1 << 27),	// Player was hit with a jar of Mad Milk. 
	TFCond_MegaHeal					= (1 << 28),	// Player is under the effect of Quick-Fix charge. 
	TFCond_RegenBuffed				= (1 << 29),	// Toggled when a player is within a Concheror's range. 
	TFCond_MarkedForDeath			= (1 << 30),	// Player is marked for death by a Fan O'War hit. Effects are similar to TFCond_Jarated. 
	TFCond_NoHealingDamageBuff		= (1 << 31),	// Unknown what this is used for.
	TFCondEx_SpeedBuffAlly			= (1 << 0),		// Toggled when a player gets hit with the disciplinary action. 
	TFCondEx_HalloweenCritCandy		= (1 << 1),		// Only for Scream Fortress event maps that drop crit candy. 
	TFCondEx_CritCanteen			= (1 << 2),		// Player is getting a crit boost from a MVM canteen.
	TFCondEx_CritDemoCharge			= (1 << 3),		// From demo's shield
	TFCondEx_CritHype				= (1 << 4),		// Soda Popper crits. 
	TFCondEx_CritOnFirstBlood		= (1 << 5),		// Arena first blood crit buff. 
	TFCondEx_CritOnWin				= (1 << 6),		// End of round crits. 
	TFCondEx_CritOnFlagCapture		= (1 << 7),		// CTF intelligence capture crits. 
	TFCondEx_CritOnKill				= (1 << 8),		// Unknown what this is for. 
	TFCondEx_RestrictToMelee		= (1 << 9),		// Unknown what this is for. 
	TFCondEx_DefenseBuffNoCritBlock = (1 << 10),	// MvM Buff.
	TFCondEx_Reprogrammed			= (1 << 11),	// MvM Bot has been reprogrammed.
	TFCondEx_PyroCrits				= (1 << 12),	// Player is getting crits from the Mmmph charge. 
	TFCondEx_PyroHeal				= (1 << 13),	// Player is being healed from the Mmmph charge. 
	TFCondEx_FocusBuff				= (1 << 14),	// Player is getting a focus buff.
	TFCondEx_DisguisedRemoved		= (1 << 15),	// Disguised remove from a bot.
	TFCondEx_MarkedForDeathSilent	= (1 << 16),	// Player is under the effects of the Escape Plan/Equalizer or GRU.
	TFCondEx_DisguisedAsDispenser	= (1 << 17),	// Bot is disguised as dispenser.
	TFCondEx_Sapped					= (1 << 18),	// MvM bot is being sapped.
	TFCondEx_UberchargedHidden		= (1 << 19),	// MvM Related
	TFCondEx_UberchargedCanteen		= (1 << 20),	// Player is receiving ÜberCharge from a canteen.
	TFCondEx_HalloweenBombHead		= (1 << 21),	// Player has a bomb on their head from Merasmus.
	TFCondEx_HalloweenThriller		= (1 << 22),	// Players are forced to dance from Merasmus.
	TFCondEx_BulletCharge			= (1 << 26),	// Player is receiving 75% reduced damage from bullets.
	TFCondEx_ExplosiveCharge		= (1 << 27),	// Player is receiving 75% reduced damage from explosives.
	TFCondEx_FireCharge				= (1 << 28),	// Player is receiving 75% reduced damage from fire.
	TFCondEx_BulletResistance		= (1 << 29),	// Player is receiving 10% reduced damage from bullets.
	TFCondEx_ExplosiveResistance	= (1 << 30),	// Player is receiving 10% reduced damage from explosives.
	TFCondEx_FireResistance			= (1 << 31),	// Player is receiving 10% reduced damage from fire.
	TFCondEx2_Stealthed				= (1 << 0),
	TFCondEx2_MedigunDebuff			= (1 << 1),
	TFCondEx2_StealthedUserBuffFade = (1 << 2),
	TFCondEx2_BulletImmune			= (1 << 3),
	TFCondEx2_BlastImmune			= (1 << 4),
	TFCondEx2_FireImmune			= (1 << 5),
	TFCondEx2_PreventDeath			= (1 << 6),
	TFCondEx2_MVMBotRadiowave		= (1 << 7),
	TFCondEx2_HalloweenSpeedBoost	= (1 << 8),		// Wheel has granted player speed boost.
	TFCondEx2_HalloweenQuickHeal	= (1 << 9),		// Wheel has granted player quick heal.
	TFCondEx2_HalloweenGiant		= (1 << 10),	// Wheel has granted player giant mode.
	TFCondEx2_HalloweenTiny			= (1 << 11),	// Wheel has granted player tiny mode.
	TFCondEx2_HalloweenInHell		= (1 << 12),	// Wheel has granted player in hell mode.
	TFCondEx2_HalloweenGhostMode	= (1 << 13),	// Wheel has granted player ghost mode.
	TFCondEx2_Parachute				= (1 << 16),	// Player has deployed the BASE Jumper.
	TFCondEx2_BlastJumping			= (1 << 17),	// Player has sticky or rocket jumped.
	TFCond_MiniCrits				= (TFCond_Buffed | TFCond_CritCola),
	TFCond_IgnoreStates				= (TFCond_Ubercharged | TFCond_Bonked),
	TFCondEx_IgnoreStates			= (TFCondEx_PyroHeal)
};

enum tfclasses_t
{
	TF2_None = 0,
	TF2_Scout,
	TF2_Sniper,
	TF2_Soldier,
	TF2_Demoman,
	TF2_Medic,
	TF2_Heavy,
	TF2_Pyro,
	TF2_Spy,
	TF2_Engineer
};

enum life_states
{
	LIFE_ALIVE,
	LIFE_DYING,
	LIFE_DEAD,
	LIFE_RESPAWNABLE,
	LIFE_DISCARDBODY,
};

class c_baseentity
{
public:

	client_networkable* get_client_networkable()
	{
		using original_fn = client_networkable * (__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 4)(this);
	}

	client_renderable* get_client_renderable()
	{
		using original_fn = client_renderable * (__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 5)(this);
	}

	PVOID get_collideable()
	{
		using original_fn = PVOID(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 3)(this);
	}

	int get_flags()
	{
		return *reinterpret_cast<int*>(uintptr_t(this) + 0x37C);
	}

	int get_team_num()
	{
		return *reinterpret_cast<int*>(uintptr_t(this) + 0xB0);
	}

	vector get_velocity()
	{
		return *reinterpret_cast<vector*>(uintptr_t(this) + 0x120);
	}

	int get_class_num()
	{
		return *reinterpret_cast<int*>(uintptr_t(this) + 0x154C);
	}

	int get_health()
	{
		using original_fn = int(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 106)(this);
	}

	BYTE get_life_state()
	{
		return *reinterpret_cast<BYTE*>(uintptr_t(this) + 0xA5);
	}

	vector& get_abs_origin()
	{
		using original_fn = vector&(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 9)(this);
	}

	vector get_eye_position()
	{
		return *reinterpret_cast<vector*>(uintptr_t(this) + 0xFC) + get_abs_origin(); // m_vecViewOffset[0]
	}

	bool is_dormant()
	{
		using original_fn = bool(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(get_client_networkable(), 8)(get_client_networkable());
	}

	vector& get_collideable_mins()
	{
		using original_fn = vector&(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(get_collideable(), 1)(get_collideable());
	}

	vector& get_collideable_maxs()
	{
		using original_fn = vector&(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(get_collideable(), 2)(get_collideable());
	}

	matrix3x4_t& get_rgfl_coordinate_frame()
	{
		using original_fn = matrix3x4_t&(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(get_client_renderable(), 34)(get_client_renderable());
	}

};

#endif // !C_BASEENTITY_H