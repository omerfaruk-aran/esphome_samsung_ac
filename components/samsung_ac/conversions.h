#pragma once

#include "esphome/components/climate/climate.h"
#include "protocol.h"

namespace esphome
{
  namespace samsung_ac
  {
    Mode str_to_mode(const char* value);
    const char* mode_to_str(Mode mode);
    
    WaterHeaterMode str_to_water_heater_mode(const char* value);
    const char* water_heater_mode_to_str(WaterHeaterMode waterheatermode);

    climate::ClimateMode mode_to_climatemode(Mode mode);
    Mode climatemode_to_mode(climate::ClimateMode mode);

    climate::ClimateFanMode fanmode_to_climatefanmode(FanMode fanmode);
    const char* fanmode_to_custom_climatefanmode(FanMode fanmode);
    FanMode climatefanmode_to_fanmode(climate::ClimateFanMode fanmode);
    FanMode customfanmode_to_fanmode(const char* value);

    const char* preset_to_altmodename(climate::ClimatePreset preset);
    climate::ClimatePreset altmodename_to_preset(const char* name);

    climate::ClimateSwingMode swingmode_to_climateswingmode(SwingMode swingMode);
    SwingMode climateswingmode_to_swingmode(climate::ClimateSwingMode swingMode);
  } // namespace samsung_ac
} // namespace esphome