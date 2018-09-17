#ifndef OpenKAI_src_Autopilot_Controller_APcopter_mission_H_
#define OpenKAI_src_Autopilot_Controller_APcopter_mission_H_

#include "../../../Base/common.h"
#include "../../ActionBase.h"
#include "APcopter_base.h"

namespace kai
{

class APcopter_mission: public ActionBase
{
public:
	APcopter_mission();
	~APcopter_mission();

	bool init(void* pKiss);
	void update(void);
	bool draw(void);
	int check(void);

public:
	APcopter_base* m_pAP;

};

}
#endif
