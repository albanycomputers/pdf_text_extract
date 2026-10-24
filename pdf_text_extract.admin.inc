<?php
/**
 * @file
 * Settings page for PDF Text Extract.
 */

/**
 * Form constructor for the settings page.
 *
 * @see pdf_text_extract_settings_form_submit()
 */
function pdf_text_extract_settings_form($form, &$form_state) {
  $config = config('pdf_text_extract.settings');
  $version = pdf_text_extract_ghostscript_version();

  $form['status'] = array(
    '#type' => 'item',
    '#title' => t('Ghostscript'),
    '#markup' => $version
      ? t('Found: version @version (%command).', array('@version' => $version, '%command' => pdf_text_extract_ghostscript()))
      : t('Not found: %command could not be run. Set its full path below.', array('%command' => pdf_text_extract_ghostscript())),
  );
  $form['ghostscript_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to Ghostscript'),
    '#description' => t('Leave empty to use %linux (Linux, macOS) or %windows (Windows) from the system path. Otherwise the full path, e.g. %example.', array(
      '%linux' => 'gs',
      '%windows' => 'gswin64c',
      '%example' => '/usr/bin/gs',
    )),
    '#default_value' => $config->get('ghostscript_path'),
  );
  $form['timeout'] = array(
    '#type' => 'number',
    '#title' => t('Time limit'),
    '#description' => t('Seconds one PDF may take before extraction is stopped.'),
    '#field_suffix' => t('seconds'),
    '#min' => 5,
    '#max' => 600,
    '#default_value' => $config->get('timeout'),
    '#required' => TRUE,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Form submission handler for pdf_text_extract_settings_form().
 */
function pdf_text_extract_settings_form_submit($form, &$form_state) {
  config('pdf_text_extract.settings')
    ->set('ghostscript_path', trim($form_state['values']['ghostscript_path']))
    ->set('timeout', (int) $form_state['values']['timeout'])
    ->save();
  backdrop_set_message(t('The configuration options have been saved.'));
}
