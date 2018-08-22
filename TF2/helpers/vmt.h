#ifndef VMT_H
#define VMT_H
#ifdef _WIN32
#pragma once
#endif

class vmt_manager {
private:
	PVOID**	base_class	= nullptr;
	PVOID*	current_vmt	= nullptr;
	PVOID*	old_vmt		= nullptr;
	size_t	size		= 0;
public:

	vmt_manager(PVOID base)
	{

		base_class	= reinterpret_cast<PVOID**>(base);
		old_vmt		= *base_class;

		size = 0;
		while (old_vmt[size] && u::is_code_ptr(old_vmt[size]))
			++size;

		current_vmt = new PVOID[size];
		memcpy(current_vmt, old_vmt, sizeof(PVOID) * size);
		*base_class = current_vmt;

	}

	~vmt_manager()
	{
		*base_class = old_vmt;
		delete[] current_vmt;
	}

	template<typename fn = uintptr_t>
	inline fn get_original_function(int index)
	{
		return reinterpret_cast<fn>(old_vmt[index]);
	}

	void hook_function(PVOID fn, const unsigned int index)
	{
		if (index <= this->size && index >= 0) {
			current_vmt[index] = reinterpret_cast<PVOID*>(fn);
		}
	}

	void un_hook_function(const unsigned int index)
	{
		if (index <= this->size && index >= 0) {
			current_vmt[index] = old_vmt[index];
		}
	}

};

#endif // !VMT_H