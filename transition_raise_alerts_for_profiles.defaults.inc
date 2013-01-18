<?php

/**
 * Helper to implementation of hook_rules_defaults().
 */
function _transition_raise_alerts_for_profiles_rules_defaults() {
  return array(
    'rules' => array(
      'transition_raise_alerts_for_profiles_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Transition - alert on profile creation',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'transition_raise_alerts_for_profiles' => 'transition_raise_alerts_for_profiles',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'initiative_profile' => 'initiative_profile',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Transition Initiative Profile created',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Send a mail to transition admin',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#name' => 'rules_action_mail',
            '#settings' => array(
              'to' => 'edmitchell@transitionnetwork.org',
              'from' => '',
              'subject' => 'New initiative profile created',
              'message' => 'initiative profile "[node:title]" created. See at [node:node-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'transition_raise_alerts_for_profiles_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Transition - alert on profile update',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'transition_raise_alerts_for_profiles' => 'transition_raise_alerts_for_profiles',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Initiative profile gets updated',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'initiative_profile' => 'initiative_profile',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'to' => 'edmitchell@transitionnetwork.org',
              'from' => '',
              'subject' => 'Transition profile updated',
              'message' => 'initiative profile "[node:title]" updated. See at [node:node-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to transition admin',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}
