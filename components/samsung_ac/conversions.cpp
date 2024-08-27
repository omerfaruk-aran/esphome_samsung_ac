#include "conversions.h"
#include <unordered_map> 

namespace esphome
{
  namespace samsung_ac
  {
    template <typename T>
    T str_to_enum(const std::string &value, const std::unordered_map<std::string, T> &mapping, T default_value)
    {
      auto it = mapping.find(value);
      if (it != mapping.end())
      {
        return it->second;
      }
      return default_value;
    }

    Mode str_to_mode(const std::string &value)
    {
      static const std::unordered_map<std::string, Mode> mode_map = {
          {"Auto", Mode::Auto},
          {"Cool", Mode::Cool},
          {"Dry", Mode::Dry},
          {"Fan", Mode::Fan},
          {"Heat", Mode::Heat}};
      return str_to_enum(value, mode_map, Mode::Unknown);
    }

    WaterHeaterMode str_to_water_heater_mode(const std::string &value)
    {
      static const std::unordered_map<std::string, WaterHeaterMode> water_heater_mode_map = {
          {"Eco", WaterHeaterMode::Eco},
          {"Standard", WaterHeaterMode::Standard},
          {"Power", WaterHeaterMode::Power},
          {"Force", WaterHeaterMode::Force}};
      return str_to_enum(value, water_heater_mode_map, WaterHeaterMode::Unknown);
    }

    std::string mode_to_str(Mode mode)
    {
      switch (mode)
      {
      case Mode::Auto:
        return "Auto";
      case Mode::Cool:
        return "Cool";
      case Mode::Dry:
        return "Dry";
      case Mode::Fan:
        return "Fan";
      case Mode::Heat:
        return "Heat";
      default:
        return "Unknown";
      };
    }

    std::string water_heater_mode_to_str(WaterHeaterMode waterheatermode)
    {
      switch (waterheatermode)
      {
      case WaterHeaterMode::Eco:
        return "Eco";
      case WaterHeaterMode::Standard:
        return "Standard";
      case WaterHeaterMode::Power:
        return "Power";
      case WaterHeaterMode::Force:
        return "Force";
      default:
        return "Unknown";
      };
    }

    template <typename T, typename U>
    optional<U> enum_to_enum(T value, const std::unordered_map<T, U> &mapping)
    {
      auto it = mapping.find(value);
      if (it != mapping.end())
      {
        return it->second;
      }
      return nullopt;
    }

    optional<climate::ClimateMode> mode_to_climatemode(Mode mode)
    {
      static const std::unordered_map<Mode, climate::ClimateMode> mapping = {
          {Mode::Auto, climate::ClimateMode::CLIMATE_MODE_AUTO},
          {Mode::Cool, climate::ClimateMode::CLIMATE_MODE_COOL},
          {Mode::Dry, climate::ClimateMode::CLIMATE_MODE_DRY},
          {Mode::Fan, climate::ClimateMode::CLIMATE_MODE_FAN_ONLY},
          {Mode::Heat, climate::ClimateMode::CLIMATE_MODE_HEAT}};
      return enum_to_enum(mode, mapping);
    }

    Mode climatemode_to_mode(climate::ClimateMode mode)
    {
      static const std::unordered_map<climate::ClimateMode, Mode> reverse_mapping = {
          {climate::ClimateMode::CLIMATE_MODE_AUTO, Mode::Auto},
          {climate::ClimateMode::CLIMATE_MODE_COOL, Mode::Cool},
          {climate::ClimateMode::CLIMATE_MODE_DRY, Mode::Dry},
          {climate::ClimateMode::CLIMATE_MODE_FAN_ONLY, Mode::Fan},
          {climate::ClimateMode::CLIMATE_MODE_HEAT, Mode::Heat}};
      return enum_to_enum(mode, reverse_mapping).value_or(Mode::Unknown);
    }

    optional<climate::ClimateFanMode> fanmode_to_climatefanmode(FanMode fanmode)
    {
      switch (fanmode)
      {
      case FanMode::Low:
        return climate::ClimateFanMode::CLIMATE_FAN_LOW;
      case FanMode::Mid:
        return climate::ClimateFanMode::CLIMATE_FAN_MIDDLE;
      case FanMode::High:
        return climate::ClimateFanMode::CLIMATE_FAN_HIGH;
      case FanMode::Turbo:
        return nullopt;
      case FanMode::Auto:
      default:
        return climate::ClimateFanMode::CLIMATE_FAN_AUTO;
      }
    }

    std::string fanmode_to_custom_climatefanmode(FanMode fanmode)
    {
      switch (fanmode)
      {
      case FanMode::Turbo:
        return "Turbo";
      default:
        return "";
      }
    }

    FanMode climatefanmode_to_fanmode(climate::ClimateFanMode fanmode)
    {
      switch (fanmode)
      {
      case climate::ClimateFanMode::CLIMATE_FAN_LOW:
        return FanMode::Low;
      case climate::ClimateFanMode::CLIMATE_FAN_MIDDLE:
        return FanMode::Mid;
      case climate::ClimateFanMode::CLIMATE_FAN_HIGH:
        return FanMode::High;
      case climate::ClimateFanMode::CLIMATE_FAN_AUTO:
      default:
        return FanMode::Auto;
      }
    }

    FanMode customfanmode_to_fanmode(const std::string &value)
    {
      if (value == "Turbo")
        return FanMode::Turbo;
      return FanMode::Auto;
    }

    AltModeName preset_to_altmodename(climate::ClimatePreset preset)
    {
      switch (preset)
      {
      case climate::ClimatePreset::CLIMATE_PRESET_ECO:
        return "Eco";
      case climate::ClimatePreset::CLIMATE_PRESET_AWAY:
        return "Away";
      case climate::ClimatePreset::CLIMATE_PRESET_BOOST:
        return "Boost";
      case climate::ClimatePreset::CLIMATE_PRESET_COMFORT:
        return "Comfort";
      case climate::ClimatePreset::CLIMATE_PRESET_HOME:
        return "Home";
      case climate::ClimatePreset::CLIMATE_PRESET_SLEEP:
        return "Sleep";
      case climate::ClimatePreset::CLIMATE_PRESET_ACTIVITY:
        return "Activity";
      case climate::ClimatePreset::CLIMATE_PRESET_NONE:
      default:
        return "None";
      }
    }

    optional<climate::ClimatePreset> altmodename_to_preset(const AltModeName &name)
    {
      if (str_equals_case_insensitive(name, "ECO"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_ECO);
      if (str_equals_case_insensitive(name, "AWAY"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_AWAY);
      if (str_equals_case_insensitive(name, "BOOST"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_BOOST);
      if (str_equals_case_insensitive(name, "COMFORT"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_COMFORT);
      if (str_equals_case_insensitive(name, "HOME"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_HOME);
      if (str_equals_case_insensitive(name, "SLEEP"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_SLEEP);
      if (str_equals_case_insensitive(name, "ACTIVITY"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_ACTIVITY);
      if (str_equals_case_insensitive(name, "NONE"))
        return optional<climate::ClimatePreset>(climate::CLIMATE_PRESET_NONE);
      return nullopt;
    }

    climate::ClimateSwingMode swingmode_to_climateswingmode(SwingMode swingMode)
    {
      switch (swingMode)
      {
      case SwingMode::Horizontal:
        return climate::ClimateSwingMode::CLIMATE_SWING_HORIZONTAL;
      case SwingMode::Vertical:
        return climate::ClimateSwingMode::CLIMATE_SWING_VERTICAL;
      case SwingMode::All:
        return climate::ClimateSwingMode::CLIMATE_SWING_BOTH;
      case SwingMode::Fix:
      default:
        return climate::ClimateSwingMode::CLIMATE_SWING_OFF;
      }
    }

    SwingMode climateswingmode_to_swingmode(climate::ClimateSwingMode swingMode)
    {
      switch (swingMode)
      {
      case climate::ClimateSwingMode::CLIMATE_SWING_HORIZONTAL:
        return SwingMode::Horizontal;
      case climate::ClimateSwingMode::CLIMATE_SWING_VERTICAL:
        return SwingMode::Vertical;
      case climate::ClimateSwingMode::CLIMATE_SWING_BOTH:
        return SwingMode::All;
      case climate::ClimateSwingMode::CLIMATE_SWING_OFF:
      default:
        return SwingMode::Fix;
      }
    }

  } // namespace samsung_ac
} // namespace esphome
