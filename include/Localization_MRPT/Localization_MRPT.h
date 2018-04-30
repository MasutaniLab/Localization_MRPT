// -*- C++ -*-
/*!
 * @file  Localization_MRPT.h
 * @brief Localization MRPT Component
 * @date  $Date$
 *
 * $Id$
 */

#ifndef LOCALIZATION_MRPT_H
#define LOCALIZATION_MRPT_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

using namespace RTC;
using namespace std;
// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "MobileRobotStub.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

/*!
 * @class Localization_MRPT
 * @brief Localization MRPT Component
 *
 */
class Localization_MRPT
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  Localization_MRPT(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~Localization_MRPT();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  min_x
   * - DefaultValue: -0.01
   */
  float m_min_x;
  /*!
   * 
   * - Name:  max_x
   * - DefaultValue: 0.01
   */
  float m_max_x;
  /*!
   * 
   * - Name:  min_y
   * - DefaultValue: -0.01
   */
  float m_min_y;
  /*!
   * 
   * - Name:  max_y
   * - DefaultValue: 0.01
   */
  float m_max_y;
  /*!
   * 
   * - Name:  min_phi
   * - DefaultValue: -0.01
   */
  float m_min_phi;
  /*!
   * 
   * - Name:  max_phi
   * - DefaultValue: 0.01
   */
  float m_max_phi;
  /*!
   * 
   * - Name:  range_min
   * - DefaultValue: 0.3
   */
  float m_range_min;
  /*!
   * 
   * - Name:  range_max
   * - DefaultValue: 10
   */
  float m_range_max;
  /*!
   * 
   * - Name:  minStdXY
   * - DefaultValue: 0.01
   */
  float m_minStdXY;
  /*!
   * 
   * - Name:  minStdPHI
   * - DefaultValue: 0.01
   */
  float m_minStdPHI;
  /*!
   * 
   * - Name:  KLD_binSize_PHI
   * - DefaultValue: 0.01
   */
  float m_KLD_binSize_PHI;
  /*!
   * 
   * - Name:  KLD_binSize_XY
   * - DefaultValue: 0.01
   */
  float m_KLD_binSize_XY;
  /*!
   * 
   * - Name:  KLD_delta
   * - DefaultValue: 0.02
   */
  float m_KLD_delta;
  /*!
   * 
   * - Name:  KLD_epsilon
   * - DefaultValue: 0.02
   */
  float m_KLD_epsilon;
  /*!
   * 
   * - Name:  KLD_maxSampleSize
   * - DefaultValue: 1000
   */
  int m_KLD_maxSampleSize;
  /*!
   * 
   * - Name:  KLD_minSampleSize
   * - DefaultValue: 150
   */
  int m_KLD_minSampleSize;
  /*!
   * 
   * - Name:  KLD_minSamplesPerBin
   * - DefaultValue: 0
   */
  double m_KLD_minSamplesPerBin;
  /*!
   * 
   * - Name:  adaptiveSampleSize
   * - DefaultValue: 1
   */
  int m_adaptiveSampleSize;
  /*!
   * 
   * - Name:  pfAuxFilterOptimal_MaximumSearchSamples
   * - DefaultValue: 10
   */
  int m_pfAuxFilterOptimal_MaximumSearchSamples;
  /*!
   * 
   * - Name:  BETA
   * - DefaultValue: 0.5
   */
  double m_BETA;
  /*!
   * 
   * - Name:  sampleSize
   * - DefaultValue: 1
   */
  int m_sampleSize;
  /*!
  // The Particle Filter algorithm:
  //	0: pfStandardProposal	  ***
  //	1: pfAuxiliaryPFStandard
  //	2: pfOptimalProposal    
  //	3: pfAuxiliaryPFOptimal	  ***
  */
  int m_PF_algorithm;
  /*!
  // The Particle Filter Resampling method:
  //	0: prMultinomial
  //	1: prResidual
  //	2: prStratified
  //	3: prSystematic
  */
  int m_resamplingMethod;
  //std::string m_rawlog_file;
  //std::string m_logOutput_dir;
  int m_particles_count;
  
  int m_occupancyGrid_count;
  int m_mapAltitude;
  int m_useMapAltitude;
  int m_maxDistanceInsertion;
  double m_maxOccupancyUpdateCertainty;
  int m_considerInvalidRangesAsFreeSpace;
  int m_decimation;
  double m_horizontalTolerance;
  double m_CFD_features_gaussian_size;
  double m_CFD_features_median_size;
  int m_wideningBeamsWithDistance;

  int m_likelihoodMethod;
  int m_enableLikelihoodCache;
  int m_LF_decimation;
  double m_LF_stdHit;
  double m_LF_maxCorrsDistance;
  double m_LF_zHit;
  double m_LF_zRandom;
  double m_LF_maxRange;
  int m_LF_alternateAverageMethod;
  int m_MI_exponent;
  int m_MI_skip_rays;
  int m_MI_ratio_max_distance;				
  int m_rayTracing_useDistanceFilter;
  int m_rayTracing_decimation;
  double m_rayTracing_stdHit;
  int m_consensus_takeEachRange;
  int m_consensus_pow;



  /*!
   * 
   * - Name:  poseTimeOut
   * - DefaultValue: 3.0
   */
  float m_poseTimeOut;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::RangeData m_range;
  /*!
   */
  InPort<RTC::RangeData> m_rangeIn;
  RTC::TimedPose2D m_odometry;
  /*!
   */
  InPort<RTC::TimedPose2D> m_odometryIn;
  RTC::TimedShort m_mode;
  /*!
   */
  InPort<RTC::TimedShort> m_modeIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedPose2D m_estimatedPose;
  /*!
   */
  OutPort<RTC::TimedPose2D> m_estimatedPoseOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_mapServerPort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  /*!
   */
  RTC::CorbaConsumer<RTC::OGMapServer> m_mapServer;
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>


	 bool m_odomUpdated, m_rangeUpdated;

	 
	 coil::TimeValue m_lastReceivedTime;

	 enum LOCALIZATION_MODE{
		 MODE_NORMAL,
		 MODE_POSE_INVALID_VALUE,
		 MODE_POSE_TIME_OUT
	 };
	 LOCALIZATION_MODE m_MODE;
	 LOCALIZATION_MODE getMode(){return m_MODE;}
};


extern "C"
{
  DLL_EXPORT void Localization_MRPTInit(RTC::Manager* manager);
};

#endif // LOCALIZATION_MRPT_H
