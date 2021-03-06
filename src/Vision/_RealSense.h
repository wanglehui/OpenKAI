/*
 * _RealSense.h
 *
 *  Created on: Apr 6, 2018
 *      Author: yankai
 */

#ifndef OpenKAI_src_Vision_RealSense_H_
#define OpenKAI_src_Vision_RealSense_H_

#include "../Base/common.h"
#include "_DepthVisionBase.h"
#include "../Utility/util.h"

#ifdef USE_REALSENSE
#include <librealsense2/rs.hpp>

namespace kai
{

class _RealSense: public _DepthVisionBase
{
public:
	_RealSense();
	virtual ~_RealSense();

	bool init(void* pKiss);
	bool start(void);
	bool draw(void);
	bool open(void);
	void close(void);

private:
	void update(void);
	static void* getUpdateThread(void* This)
	{
		((_RealSense *) This)->update();
		return NULL;
	}

	void updateTPP(void);
	static void* getTPP(void* This)
	{
		((_RealSense*) This)->updateTPP();
		return NULL;
	}

public:
	rs2::pipeline m_rsPipe;
	rs2::frame m_rsColor;
	rs2::frame m_rsDepth;
	rs2::frame m_rsDepthShow;
	rs2::align* m_rspAlign;
    rs2::spatial_filter m_rsfSpat;
    rs2::decimation_filter m_rsfDec;
    float m_fDec;
    float m_fSpat;
    bool m_bAlign;

	int	m_rsFPS;
	int m_rsDFPS;
	bool m_rsRGB;
	string m_vPreset;

	//depth filter processing thread
	_ThreadBase* m_pTPP;

};

}
#endif
#endif
