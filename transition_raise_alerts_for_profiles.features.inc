<?php

/**
 * Implementation of hook_rules_defaults().
 */
function transition_raise_alerts_for_profiles_rules_defaults() {
  module_load_include('inc', 'transition_raise_alerts_for_profiles', 'transition_raise_alerts_for_profiles.defaults');
  $args = func_get_args();
  return call_user_func_array('_transition_raise_alerts_for_profiles_rules_defaults', $args);
}
