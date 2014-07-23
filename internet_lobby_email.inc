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
  if (user_access('administer')) {
    db_merge('admin_mail')
      -> key(array('id' => '1'))
      -> fields(array(
        'mail' => $form_state['values']['mail'],
      )
    )
    -> execute();
  }
  else {
    drupal_set_message(t("You don't have enough authority"));
  }
}