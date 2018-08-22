#ifndef ICLIENTENTITYLIST_H
#define ICLIENTENTITYLIST_H
#ifdef _WIN32
#pragma once
#endif

class icliententitylist
{
public:
	virtual client_networkable*	get_client_networkable(int index)						= 0;
	virtual client_networkable*	get_client_networkable_from_handle(base_handle ent)		= 0;
	virtual client_unknown*		get_client_unknown_handle(base_handle ent)				= 0;
	virtual client_entity*		get_client_entity(int index)							= 0;
	virtual client_entity*		get_client_entity_from_handle(base_handle ent)			= 0;
	virtual int					number_of_entities(bool include_non_networkable)		= 0;
	virtual int					get_highest_entity_index(void)							= 0;
	virtual void				set_max_entities(int ents)								= 0;
	virtual int					get_max_entities()										= 0;
};

#endif // !ICLIENTENTITYLIST_H