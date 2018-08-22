#ifndef UTIL_H
#define UTIL_H
#ifdef _WIN32
#pragma once
#endif

#define in_range(x, a, b) (x >= a && x <= b) 
#define get_bits(x) (in_range((x & (~0x20)),'A','F') ? ((x & (~0x20)) - 'A' + 0xa) : (in_range(x,'0','9') ? x - '0' : 0))
#define get_byte(x) (get_bits(x[0]) << 4 | get_bits(x[1]))

#define M_PI		3.14159265358979323846f
#define M_RADPI		57.295779513082f
#define M_PI_F		((float)(M_PI))
#define RAD2DEG(x)  ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x)  ((float)(x) * (float)(M_PI_F / 180.f))

namespace u
{

	template<typename fn>
	inline fn call_vfunc(const PVOID virt, int index)
	{
		return (fn)*(*(const PVOID**)virt + index);
	}

	inline bool is_code_ptr(PVOID ptr)
	{
		constexpr const DWORD protect_flags = PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;

		MEMORY_BASIC_INFORMATION out;
		VirtualQuery(ptr, &out, sizeof out);

		return out.Type && !(out.Protect & (PAGE_GUARD | PAGE_NOACCESS)) && out.Protect & protect_flags;
	}

	inline uint64_t find_signature(const char* module, const char* signature)
	{

		MODULEINFO module_info;
		GetModuleInformation(GetCurrentProcess(), GetModuleHandleA(module), &module_info, sizeof(MODULEINFO));

		DWORD		start_address	= (DWORD)module_info.lpBaseOfDll;
		DWORD		end_address		= start_address + module_info.SizeOfImage;
		const char*	pat				= signature;
		DWORD		first_match		= 0;

		for (DWORD cur = start_address; cur < end_address; cur++) {

			if (!*pat) 
				return first_match;

			if (*(PBYTE)pat == '\?' || *(BYTE*)cur == get_byte(pat)) {

				if (!first_match) 
					first_match = cur;

				if (!pat[2]) 
					return first_match;

				if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') 
					pat += 3;

				else pat += 2;
			} else {
				pat			= signature;
				first_match	= 0;
			}

		}

		return NULL;

	}

}

#endif // !UTIL_H