//Filename    : OF_INN.H
//Description : Header of FirmInn

#ifndef __OF_INN_H
#define __OF_INN_H

#ifndef __OUNIT_H
#include <OUNIT.h>
#endif

#ifndef __OSKILL_H
#include <OSKILL.h>
#endif

#ifndef __OFIRM_H
#include <OFIRM.h>
#endif

//----------- Define constant --------------//

#define MAX_INN_UNIT 		6  		// maximum no. of units allowed in the hire waiting list

//------- define struct InnUnit ---------//

struct InnUnit
{
public:
	char  unit_id;
	Skill skill;
	short hire_cost;
	short stay_count;		// how long this unit is going to stay until it leaves the inn if you do not hire him.
	short spy_recno;		// >0 if this unit is a spy

public:
	void	set_hire_cost();
};

//------- Define class FirmInn --------//

class FirmInn : public Firm
{
public:
	short			 next_skill_id;		// the skill id. of the next available unit

	InnUnit 		 inn_unit_array[MAX_INN_UNIT];
	short			 inn_unit_count;

public:
	FirmInn();
	~FirmInn();

	void 		init_derived();

	void 		put_info(int);
	void 		detect_info();
	void		put_det(int);

	void		next_day();
	void		assign_unit(int unitRecno);

	int		hire(short recNo);

	virtual	void auto_defense(short targetRecno);
	virtual	FirmInn* cast_to_FirmInn() { return this; };

	void		process_ai();

	//-------------- multiplayer checking codes ---------------//
	virtual	UCHAR crc8();
	virtual	void	clear_ptr();

private:
	int 		should_add_inn_unit();

	void 		add_inn_unit(int unitId);
	void 		del_inn_unit(int recNo);

	void 		update_add_hire_list();
	void 		update_del_hire_list();

	void 		disp_unit_info(int dispY1, InnUnit* hireInfoPtr, int refreshFlag);

	//-------- AI actions ---------//

	int		think_del();
	int 		think_hire_spy();
	int 		think_assign_spy_to(int raceId, int innUnitRecno);
	int 		think_hire_general();
	int 		think_assign_general_to(int raceId, int innUnitRecno);
};

//--------------------------------------//

#endif
