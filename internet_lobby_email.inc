<?php
/**
  * Build mail form
  */
function internet_lobby_email_page_form($form, $form_state) {
  $form['mail'] = array (
    '#type' => 'textfield',
    '#title' => t('E-mail you want to use'),
    '#required' => TRUE,
  );
  $form['submit'] = array (
    '#type' => 'submit',
    '#value' => t('Send'),
    '#required' => TRUE,
  );
  return $form;
}

/**
  * Submit function for internet_lobby_email_page_form.
  */
function internet_lobby_email_page_form_submit($form, &$form_state) {
  variable_set('admin_mail', $form_state['values']['mail']);
}