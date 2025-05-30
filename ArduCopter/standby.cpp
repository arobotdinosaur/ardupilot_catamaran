#include "Copter.h"

// Run standby functions at approximately 100 Hz to limit maximum variable build up
//
// When standby is active:
//      all I terms are continually reset
//      heading error is reset to zero
//      position errors are reset to zero
//      crash_check is disabled
//      thrust_loss_check is disabled
//      parachute_check is disabled
//      hover throttle learn is disabled
//      and landing detection is disabled.
void Copter::standby_update()
{
    if (!standby_active) {
        return;
    }

    attitude_control->reset_rate_controller_I_terms();
    attitude_control->reset_yaw_target_and_rate();
    pos_control->standby_NEU_reset();
}
