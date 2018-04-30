// -*- C++ -*-
/*!
 * @file  Localization_MRPT.cpp
 * @brief Localization MRPT Component
 * @date $Date$
 *
 * $Id$
 */

#include "Localization_MRPT.h"
#include "MonteCarloLocalization.h"

// Module specification
// <rtc-template block="module_spec">
static const char* localization_mrpt_spec[] =
  {
    "implementation_id", "Localization_MRPT",
    "type_name",         "Localization_MRPT",
    "description",       "Localization MRPT Component",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Navigation",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.min_x", "-0.01",
    "conf.default.max_x", "0.01",
    "conf.default.min_y", "-0.01",
    "conf.default.max_y", "0.01",
    "conf.default.min_phi", "-0.05",
    "conf.default.max_phi", "0.05",
    "conf.default.range_min", "0.3",
    "conf.default.range_max", "10",
    "conf.default.gausianModel_minStdXY", "0.1",
    "conf.default.gausianModel_minStdPHI", "2.0",
    "conf.default.KLD_binSize_PHI", "20",
    "conf.default.KLD_binSize_XY", "0.2",
    "conf.default.KLD_delta", "0.02",
    "conf.default.KLD_epsilon", "0.02",
    "conf.default.KLD_maxSampleSize", "1000",
    "conf.default.KLD_minSampleSize", "150",
    "conf.default.KLD_minSamplesPerBin", "0",
    "conf.default.adaptiveSampleSize", "1",
    "conf.default.pfAuxFilterOptimal_MaximumSearchSamples", "10",
    "conf.default.BETA", "0.5",
	"conf.default.sampleSize", "1",
    "conf.default.PF_algorithm", "pfStandardProposal",
    "conf.default.resamplingMethod", "prMultinomials",
    //"conf.default.rawlog_file", "",
    //"conf.default.logOutput_dir", "LOG_LOCALIZATION",
    "conf.default.particles_count", "1000",
	
    "conf.default.occupancyGrid_count","1",
    "conf.default.mapAltitude","0",
    "conf.default.useMapAltitude","0",
    "conf.default.maxDistanceInsertion","15",
    "conf.default.maxOccupancyUpdateCertainty","0.55",
    "conf.default.considerInvalidRangesAsFreeSpace","1",
	"conf.default.decimation","1",
	"conf.default.horizontalTolerance","0.000873",
	"conf.default.CFD_features_gaussian_size","1.0",
	"conf.default.CFD_features_median_size","3.0",
	"conf.default.wideningBeamsWithDistance","0",

    "conf.default.likelihoodMethod","4",	
    "conf.default.enableLikelihoodCache","1",
    "conf.default.LF_decimation","20",
    "conf.default.LF_stdHit","0.20",
    "conf.default.LF_maxCorrsDistance","0.30",
    "conf.default.LF_zHit","0.95",
    "conf.default.LF_zRandom","0.05",
    "conf.default.LF_maxRange","80",
    "conf.default.LF_alternateAverageMethod","0",
    "conf.default.MI_exponent","10",
    "conf.default.MI_skip_rays","10",
    "conf.default.MI_ratio_max_distance","2",				
    "conf.default.rayTracing_useDistanceFilter","0",
    "conf.default.rayTracing_decimation","10",
    "conf.default.rayTracing_stdHit","0.30",
    "conf.default.consensus_takeEachRange","30",
    "conf.default.consensus_pow","1",
	
    "conf.default.poseTimeOut", "3.0",
    // Widget
    "conf.__widget__.min_x", "text",
    "conf.__widget__.max_x", "text",
    "conf.__widget__.min_y", "text",
    "conf.__widget__.max_y", "text",
    "conf.__widget__.min_phi", "text",
    "conf.__widget__.max_phi", "text",
    "conf.__widget__.range_min", "text",
    "conf.__widget__.range_max", "text",
    "conf.__widget__.gausianModel_minStdXY", "text",
    "conf.__widget__.gausianModel_minStdPHI", "text",
    "conf.__widget__.KLD_binSize_PHI", "text",
    "conf.__widget__.KLD_binSize_XY", "text",
    "conf.__widget__.KLD_delta", "text",
    "conf.__widget__.KLD_epsilon", "text",
    "conf.__widget__.KLD_maxSampleSize", "text",
    "conf.__widget__.KLD_minSampleSize", "text",
    "conf.__widget__.KLD_minSamplesPerBin", "text",
    "conf.__widget__.adaptiveSampleSize", "text",
    "conf.__widget__.pfAuxFilterOptimal_MaximumSearchSamples", "text",
    "conf.__widget__.BETA", "text",
    "conf.__widget__.sampleSize", "text",
	"conf.__widget__.PF_algorithm", "radio",
    "conf.__widget__.resamplingMethod", "radio",
    //"conf.__widget__.rawlog_file", "text",
    //"conf.__widget__.logOutput_dir", "text",
    "conf.__widget__.particles_count", "text",

    "conf.__widget__.occupancyGrid_count","text",
    "conf.__widget__.mapAltitude","text",
    "conf.__widget__.useMapAltitude","text",
    "conf.__widget__.maxDistanceInsertion","text",
    "conf.__widget__.maxOccupancyUpdateCertainty","text",
    "conf.__widget__.considerInvalidRangesAsFreeSpace","text",
    "conf.__widget__.decimation","text",
	"conf.__widget__.horizontalTolerance","text",
	"conf.__widget__.CFD_features_gaussian_size","text",
	"conf.__widget__.CFD_features_median_size","text",
	"conf.__widget__.wideningBeamsWithDistance","text",

    "conf.__widget__.likelihoodMethod","text",
    "conf.__widget__.enableLikelihoodCache","text",
    "conf.__widget__.LF_decimation","text",
    "conf.__widget__.LF_stdHit","text",
    "conf.__widget__.LF_maxCorrsDistance","text",
    "conf.__widget__.LF_zHit","text",
    "conf.__widget__.LF_zRandom","text",
    "conf.__widget__.LF_maxRange","text",
    "conf.__widget__.LF_alternateAverageMethod","text",
    "conf.__widget__.MI_exponent","text",
    "conf.__widget__.MI_skip_rays","text",
    "conf.__widget__.MI_ratio_max_distance","text",				
    "conf.__widget__.rayTracing_useDistanceFilter","text",
    "conf.__widget__.rayTracing_decimation","text",
    "conf.__widget__.rayTracing_stdHit","text",
    "conf.__widget__.consensus_takeEachRange","text",
    "conf.__widget__.consensus_pow","text",

    "conf.__widget__.poseTimeOut", "text",
    // Constraints
	 "conf.__constraints__.PF_algorithm", "(pfStandardProposal,  pfAuxiliaryPFStandard, pfOptimalProposal, pfAuxiliaryPFOptimal)",
     "conf.__constraints__.resamplingMethod", "(prMultinomials, prResidual, prStratified, prSystematic)",
    ""
  };
// </rtc-template>
/*!
 * @brief constructor
 * @param manager Maneger Object
 */

ssr::Pose2D OldPose;
ssr::MCLocalization_MRPT mcl;

Localization_MRPT::Localization_MRPT(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rangeIn("range", m_range),
    m_odometryIn("odometry", m_odometry),
    m_modeIn("mode", m_mode),
    m_estimatedPoseOut("estimatedPose", m_estimatedPose),
    m_mapServerPort("mapServer")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Localization_MRPT::~Localization_MRPT()
{
}



RTC::ReturnCode_t Localization_MRPT::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("range", m_rangeIn);
  addInPort("odometry", m_odometryIn);
  addInPort("mode", m_modeIn);
  
  // Set OutPort buffer
  addOutPort("estimatedPose", m_estimatedPoseOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_mapServerPort.registerConsumer("mapServer", "RTC::OGMapServer", m_mapServer);
  
  // Set CORBA Service Ports
  addPort(m_mapServerPort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("min_x", m_min_x, "-0.01");
  bindParameter("max_x", m_max_x, "0.01");
  bindParameter("min_y", m_min_y, "-0.01");
  bindParameter("max_y", m_max_y, "0.01");
  bindParameter("min_phi", m_min_phi, "-0.01");
  bindParameter("max_phi", m_max_phi, "0.01");
  bindParameter("range_min", m_range_min, "0.3");
  bindParameter("range_max", m_range_max, "10");
  bindParameter("gausianModel_minStdXY", m_minStdXY, "0.01");
  bindParameter("gausianModel_minStdPHI", m_minStdPHI, "0.01");
  bindParameter("KLD_binSize_PHI", m_KLD_binSize_PHI, "0.01");
  bindParameter("KLD_binSize_XY", m_KLD_binSize_XY, "0.01");
  bindParameter("KLD_delta", m_KLD_delta, "0.02");
  bindParameter("KLD_epsilon", m_KLD_epsilon, "0.02");
  bindParameter("KLD_maxSampleSize", m_KLD_maxSampleSize, "1000");
  bindParameter("KLD_minSampleSize", m_KLD_minSampleSize, "150");
  bindParameter("KLD_minSamplesPerBin", m_KLD_minSamplesPerBin, "0");
  bindParameter("adaptiveSampleSize", m_adaptiveSampleSize, "1");
  bindParameter("pfAuxFilterOptimal_MaximumSearchSamples", m_pfAuxFilterOptimal_MaximumSearchSamples, "10");
  bindParameter("BETA", m_BETA, "0.5");
  bindParameter("sampleSize", m_sampleSize, "1");
  bindParameter("PF_algorithm", m_PF_algorithm,"0");
  bindParameter("resamplingMethod",m_resamplingMethod, "0");	
  //bindParameter("rawlog_file",m_rawlog_file, "");
  //bindParameter("logOutput_dir", m_logOutput_dir,"LOG_LOCALIZATION");
  bindParameter("particles_count", m_particles_count,"1000");
  
  bindParameter("occupancyGrid_count", m_occupancyGrid_count,"1");
  bindParameter("mapAltitude", m_mapAltitude, "0");
  bindParameter("useMapAltitude", m_useMapAltitude, "0");
  bindParameter("maxDistanceInsertion", m_maxDistanceInsertion, "15");
  bindParameter("maxOccupancyUpdateCertainty", m_maxOccupancyUpdateCertainty, "0.55");
  bindParameter("considerInvalidRangesAsFreeSpace", m_considerInvalidRangesAsFreeSpace, "1");
  bindParameter("decimation", m_decimation, "1");
  bindParameter("horizontalTolerance", m_horizontalTolerance,"0.000873");
  bindParameter("CFD_features_gaussian_size", m_CFD_features_gaussian_size,"1.0");
  bindParameter("CFD_features_median_size", m_CFD_features_median_size,"3.0");
  bindParameter("wideningBeamsWithDistance", m_wideningBeamsWithDistance,"0");

  bindParameter("likelihoodMethod", m_likelihoodMethod, "4");
  bindParameter("enableLikelihoodCache", m_enableLikelihoodCache, "1");
  bindParameter("LF_decimation", m_LF_decimation, "20");
  bindParameter("LF_stdHit", m_LF_stdHit, "0.20");
  bindParameter("LF_maxCorrsDistance", m_LF_maxCorrsDistance, "0.30");
  bindParameter("LF_zHit", m_LF_zHit, "0.95");
  bindParameter("LF_zRandom", m_LF_zRandom, "0.05");
  bindParameter("LF_maxRange", m_LF_maxRange, "80");
  bindParameter("LF_alternateAverageMethod", m_LF_alternateAverageMethod, "0");
  bindParameter("MI_exponent", m_MI_exponent, "10");
  bindParameter("MI_skip_rays", m_MI_skip_rays, "10");
  bindParameter("MI_ratio_max_distance", m_MI_ratio_max_distance, "2");				
  bindParameter("rayTracing_useDistanceFilter", m_rayTracing_useDistanceFilter, "0");
  bindParameter("rayTracing_decimation", m_rayTracing_decimation, "10");
  bindParameter("rayTracing_stdHit", m_rayTracing_stdHit, "0.30");
  bindParameter("consensus_takeEachRange", m_consensus_takeEachRange, "30");
  bindParameter("consensus_pow", m_consensus_pow, "1");


  bindParameter("poseTimeOut", m_poseTimeOut, "3.0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Localization_MRPT::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPT::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPT::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Localization_MRPT::onActivated(RTC::UniqueId ec_id)
{
  m_MODE = MODE_NORMAL;  
  m_lastReceivedTime = coil::gettimeofday();

  //Load OGMap
  OGMap* ogmap = new OGMap();
  while (m_mapServerPort.get_connector_profiles()->length() == 0) {
	  coil::sleep(1);
	  std::cout << "[RTC::Localization_MRPT] Waiting for Map Server Connection" << std::endl;
  }

  RTC::ConnectorProfileList& pList = *(m_mapServerPort.get_connector_profiles());
  RTC::RTObjectRef rto = (RTObjectRef)pList[0].ports[0]->get_port_profile()->owner;
  if(std::string((const char*)rto->get_component_profile()->instance_name) == this->getInstanceName()) {
    rto = (RTObjectRef)pList[0].ports[1]->get_port_profile()->owner;
  }
  do {
	  coil::sleep(1);
	  std::cout << "[RTC::Localization_MRPT] Waiting for Map Server Activation" << std::endl;
	  if((*(rto->get_owned_contexts()))[0]->get_component_state(rto) == RTC::ERROR_STATE) {
		  std::cout << "[RTC::Localization_MRPT] Map Server RTC is now in ERROR_STATE" << std::endl;
		  return RTC::RTC_ERROR;
	  }
  } while ((*(rto->get_owned_contexts()))[0]->get_component_state(rto) != RTC::ACTIVE_STATE);

  RTC::RETURN_VALUE ret = m_mapServer->requestCurrentBuiltMap(ogmap); 

  if (ret != RTC::RETVAL_OK) {
	  std::cout << "[RTC::Localization_MRPT] Acquiring Map from Server Failed." << std::endl;
  }

  std::cout << "[RTC::Localization_MRPT] Initializing Monte Carlo Localization." << std::endl;

  mcl.setMap(*ogmap);
  
  mcl.m_PF_algorithm = mrpt::bayes::CParticleFilter::TParticleFilterAlgorithm(m_PF_algorithm);
  mcl.m_resamplingMethod =  mrpt::bayes::CParticleFilter::TParticleResamplingAlgorithm(m_resamplingMethod);
  mcl.m_min_x = m_min_x;
  mcl.m_max_x = m_max_x;
  mcl.m_min_y = m_min_y;
  mcl.m_max_y = m_max_y;
  mcl.m_min_phi = m_min_phi;
  mcl.m_max_phi = m_max_phi;
  mcl.m_range_min = m_range_min;
  mcl.m_range_max = m_range_max;
  mcl.m_particles_count = m_particles_count;

  mcl.m_minStdXY = m_minStdXY;
  mcl.m_minStdPHI = m_minStdPHI;
  mcl.m_KLD_binSize_PHI = m_KLD_binSize_PHI;
  mcl.m_KLD_binSize_XY = m_KLD_binSize_XY;
  mcl.m_KLD_delta = m_KLD_delta;
  mcl.m_KLD_epsilon = m_KLD_epsilon;
  mcl.m_KLD_maxSampleSize = m_KLD_maxSampleSize;
  mcl.m_KLD_minSampleSize = m_KLD_minSampleSize;
  mcl.m_KLD_minSamplesPerBin = m_KLD_minSamplesPerBin;
  mcl.m_adaptiveSampleSize = m_adaptiveSampleSize;
  mcl.m_pfAuxFilterOptimal_MaximumSearchSamples = m_pfAuxFilterOptimal_MaximumSearchSamples;
  mcl.m_BETA = m_BETA;
  mcl.m_sampleSize = m_sampleSize;
  
  mcl.m_mapAltitude = m_mapAltitude;
  mcl.m_useMapAltitude = m_useMapAltitude;
  mcl.m_maxDistanceInsertion = m_maxDistanceInsertion;
  mcl.m_maxOccupancyUpdateCertainty = m_maxOccupancyUpdateCertainty;
  mcl.m_considerInvalidRangesAsFreeSpace = m_considerInvalidRangesAsFreeSpace;
  mcl.m_decimation = m_decimation;
  mcl.m_horizontalTolerance =  m_horizontalTolerance; 
  mcl.m_CFD_features_gaussian_size = m_CFD_features_gaussian_size;
  mcl.m_CFD_features_median_size = m_CFD_features_median_size;
  mcl.m_wideningBeamsWithDistance = m_wideningBeamsWithDistance;

  mcl.m_likelihoodMethod = mrpt::maps::COccupancyGridMap2D::TLikelihoodMethod(m_likelihoodMethod);
  mcl.m_enableLikelihoodCache = m_enableLikelihoodCache;
  mcl.m_LF_decimation= m_LF_decimation;
  mcl.m_LF_stdHit= m_LF_stdHit;
  mcl.m_LF_maxCorrsDistance=  m_LF_maxCorrsDistance;
  mcl.m_LF_zHit= m_LF_zHit; 
  mcl.m_LF_zRandom=  m_LF_zRandom; 
  mcl.m_LF_maxRange=  m_LF_maxRange;
  mcl.m_LF_alternateAverageMethod= m_LF_alternateAverageMethod;
  mcl.m_MI_exponent= m_MI_exponent;
  mcl.m_MI_skip_rays= m_MI_skip_rays;
  mcl.m_MI_ratio_max_distance= m_MI_ratio_max_distance;		
  mcl.m_rayTracing_useDistanceFilter= m_rayTracing_useDistanceFilter;
  mcl.m_rayTracing_decimation= m_rayTracing_decimation;
  mcl.m_rayTracing_stdHit= m_rayTracing_stdHit;
  mcl.m_consensus_takeEachRange= m_consensus_takeEachRange;
  mcl.m_consensus_pow= m_consensus_pow;


  mcl.initialize();

  OldPose.x = 0;
  OldPose.y = 0;
  OldPose.th = 0;

  m_odomUpdated = m_rangeUpdated = false;
  std::cout << "[RTC::Localization_MRPT] Successfully Activated." << std::endl;
  m_mode.data = 1; //1‚Å’Êí‚Ì“®ì
  return RTC::RTC_OK;

}

RTC::ReturnCode_t Localization_MRPT::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Localization_MRPT::onExecute(RTC::UniqueId ec_id)
{
  coil::TimeValue currentTime = coil::gettimeofday();

  if (m_modeIn.isNew()) {
    m_modeIn.read();
  }

  if(m_odometryIn.isNew()){
	  m_odometryIn.read();
      if (m_mode.data == 0) { //0‚Ìê‡‚Íodometry‚ð‘f’Ê‚µ
        m_estimatedPose = m_odometry;
        m_estimatedPoseOut.write();
        return RTC::RTC_OK;
      }
	  ssr::Pose2D CurrentPose(m_odometry.data.position.x, m_odometry.data.position.y, m_odometry.data.heading);
      ssr::Pose2D deltaPose = CurrentPose - OldPose;
	  if(deltaPose.x < -5 || deltaPose.x >5){// the number should be add configuration
		m_MODE = MODE_POSE_INVALID_VALUE;
		m_estimatedPoseOut.disconnect("estimatedPose");
	  }else if(deltaPose.y < -5 || deltaPose.y >5){
		m_MODE = MODE_POSE_INVALID_VALUE;
		m_estimatedPoseOut.disconnect("estimatedPose");
	  }
	  OldPose = CurrentPose;
	  mcl.addPose(deltaPose);
	  m_odomUpdated = true;
	  	  
      m_lastReceivedTime = currentTime;
  }else {
    double duration = currentTime - m_lastReceivedTime;
    if (duration > m_poseTimeOut && m_poseTimeOut > 0) {
      m_MODE = MODE_POSE_TIME_OUT;
	  m_estimatedPoseOut.disconnect("estimatedPose");
    }
  }

  if(m_rangeIn.isNew()){
	  m_rangeIn.read();
	  ssr::Range range(&(m_range.ranges[0]), m_range.ranges.length(), m_range.config.maxAngle - m_range.config.minAngle);
	  mcl.addRange(range);
	  m_rangeUpdated = true;
  }

  if(m_rangeUpdated && m_odomUpdated) {
    mrpt::poses::CPose2D estPose;
    estPose = mcl.getEstimatedPose();
	m_estimatedPose.data.position.x = estPose.x();
	m_estimatedPose.data.position.y = estPose.y();
	m_estimatedPose.data.heading    = estPose.phi();
	setTimestamp<TimedPose2D>(m_estimatedPose);
	m_estimatedPoseOut.write();
  }
  
  return RTC::RTC_OK;
}




/*
RTC::ReturnCode_t Localization_MRPT::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPT::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPT::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPT::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Localization_MRPT::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Localization_MRPTInit(RTC::Manager* manager)
  {
    coil::Properties profile(localization_mrpt_spec);
    manager->registerFactory(profile,
                             RTC::Create<Localization_MRPT>,
                             RTC::Delete<Localization_MRPT>);
  }
  
};


