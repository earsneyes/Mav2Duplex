/*
         APM2EX Version 1.0 
         based on Mav2DupEx Version 0.1 2014, by DevFor8.com, info@devfor8.com
	 
         schiwo1@gmail.com March 2015
	 part of code is based on ArduCAM OSD
*/
	 
	 /*Panels variables*/
//Will come from APM telem port

static short        base_mode=0;
static short        motor_armed = 0;

static float        osd_vbat_A = -1;                 // Battery A voltage in milivolt
static float        osd_curr_A = -1;                 // Battery A current
static short        osd_battery_remaining_A = 0;    // 0 to 100 <=> 0 to 1000
static short        osd_capacity_mA = 0;
static uint8_t      osd_mode = 0;                   // Navigation mode from RC AC2 = CH5, APM = CH8
static float        osd_climb = 0;

// fix by rosewhite
//static float        osd_lat = 0;                    // latidude
//static float        osd_lon = 0;                    // longitude
static float          osd_lat = 0.00f;                // latidude (i.e. -48.600000f)
static float          osd_lon = 0.00f;                // longitude
static long           osd_lat_org = 0;                // stores the received coordinate in its original high resolution form (i.e. -486000000)
static long           osd_lon_org = 0;
static uint8_t        gps_lat [4] = {78, 0, 0, 0};
static uint8_t        gps_lon [4] = {69, 0, 0, 0};
// end fix
static short        osd_satellites_visible = 0;     // number of satelites
static uint8_t      osd_fix_type = 0;               // GPS lock 0-1=no fix, 2=2D, 3=3D
static float        ap_gps_hdop = 0;                //hdop value 
static short        osd_fix_type_jeti = 0;     // GPS lock 0=no GPS, 1=no fix, 2=2D, 3=3D

static uint8_t      osd_got_home = 0;               // tels if got home position or not
static float        osd_home_lat = 0;               // home latidude
static float        osd_home_lon = 0;               // home longitude
static float        osd_home_alt = -9; 
static short      osd_home_distance = 0;          // distance from home
static short      osd_home_altdif = -9;          // distance from home
static short      osd_home_heading = 0;             // Arrow direction pointing to home (1-16 to CW loop)

static short       osd_pitch = 0;                  // pitch from DCM
static short       osd_roll = 0;                   // roll from DCM
static short       osd_yaw = 0;                    // relative heading form DCM
static float       osd_heading = 0;                // ground course heading from GPS

static float        osd_alt = 0;                    // altitude
static float        osd_baro_alt = 0;                    // altitude

static uint8_t      osd_alt_cnt = 0;              // counter for stable osd_alt
static float        osd_alt_prev = 0;             // previous altitude

static float        osd_groundspeed = 0;            // ground speed
static float        osd_airspeed = -1;              // airspeed
static uint16_t     osd_throttle = 0;               // throtle

//MAVLink session control
static boolean      mavbeat = 0;
static float        lastMAVBeat = 0;
static boolean      waitingMAVBeats = 1;
static uint8_t      apm_mav_type;
static int8_t      apm_mav_system; 
static uint8_t      apm_mav_component;
static boolean      enable_mav_request = 0;

static char         LastMessage[LCDMaxPos];

static short      debug1 = 0;
static short      debug2 = 0;
static float        debug3 = 0;
