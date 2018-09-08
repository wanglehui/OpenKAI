#ifndef OpenKAI_src_Autopilot_Controller_APcopter_DNNfollow_H_
#define OpenKAI_src_Autopilot_Controller_APcopter_DNNfollow_H_

#include "../../../Base/common.h"
#include "../../../Base/_ObjectBase.h"
#include "../../../Vision/_DepthVisionBase.h"
#include "../../../Tracker/_TrackerBase.h"
#include "../../ActionBase.h"
#include "APcopter_base.h"

namespace kai
{

class APcopter_DNNfollow: public ActionBase
{
public:
	APcopter_DNNfollow();
	~APcopter_DNNfollow();

	bool init(void* pKiss);
	void update(void);
	bool draw(void);
	bool cli(int& iY);
	int check(void);

	OBJECT* newFound(void);
	void search(void);
	void releaseRC(void);

public:
	APcopter_base* m_pAP;
	_ObjectBase* m_pDet;
	uint64_t m_tStampDet;
	_DepthVisionBase* m_pDV;
	_TrackerBase* m_pTracker;
	uint64_t m_timeOut;
	uint64_t m_timeOn;

	bool	 m_bUseTracker;
	bool	 m_bFollowing;
	int		 m_iClass;
	vDouble3 m_vTarget;
	vDouble3 m_vPos;
	uint32_t m_iModeEnable;

	PIDctrl* m_pRoll;
	PIDctrl* m_pPitch;
	PIDctrl* m_pYaw;
	PIDctrl* m_pAlt;

	uint16_t m_pwmLow;
	uint16_t m_pwmMidR;
	uint16_t m_pwmMidP;
	uint16_t m_pwmMidY;
	uint16_t m_pwmMidA;
	uint16_t m_pwmHigh;

	uint16_t m_pwmYawSearch;
	double m_searchFrom;
	double m_searchTo;

};

}
#endif