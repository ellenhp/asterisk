/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 2012 - 2013, Digium, Inc.
 *
 * David M. Lee, II <dlee@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !!!!!                               DO NOT EDIT                        !!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This file is generated by a mustache template. Please see the original
 * template in rest-api-templates/res_ari_resource.c.mustache
 */

/*! \file
 *
 * \brief Recording resources
 *
 * \author David M. Lee, II <dlee@digium.com>
 */

/*** MODULEINFO
	<depend type="module">res_ari</depend>
	<depend type="module">res_ari_model</depend>
	<depend type="module">res_stasis</depend>
	<depend type="module">res_stasis_recording</depend>
	<support_level>core</support_level>
 ***/

#include "asterisk.h"

#include "asterisk/app.h"
#include "asterisk/module.h"
#include "asterisk/stasis_app.h"
#include "ari/resource_recordings.h"
#if defined(AST_DEVMODE)
#include "ari/ari_model_validators.h"
#endif

#define MAX_VALS 128

/*!
 * \brief Parameter parsing callback for /recordings/stored.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_list_stored_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_list_stored_args args = {};
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	ast_ari_recordings_list_stored(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_list(response->message,
				ast_ari_validate_stored_recording_fn());
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/stored\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/stored\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/stored/{recordingName}.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_get_stored_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_get_stored_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_get_stored(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_stored_recording(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/stored/{recordingName}\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/stored/{recordingName}\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/stored/{recordingName}.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_delete_stored_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_delete_stored_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_delete_stored(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/stored/{recordingName}\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/stored/{recordingName}\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/stored/{recordingName}/file.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_get_stored_file_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_get_stored_file_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_get_stored_file(ser, headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 403: /* The recording file could not be opened */
	case 404: /* Recording not found */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			/* No validation on a raw binary response */
			is_valid = 1;
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/stored/{recordingName}/file\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/stored/{recordingName}/file\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
int ast_ari_recordings_copy_stored_parse_body(
	struct ast_json *body,
	struct ast_ari_recordings_copy_stored_args *args)
{
	struct ast_json *field;
	/* Parse query parameters out of it */
	field = ast_json_object_get(body, "destinationRecordingName");
	if (field) {
		args->destination_recording_name = ast_json_string_get(field);
	}
	return 0;
}

/*!
 * \brief Parameter parsing callback for /recordings/stored/{recordingName}/copy.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_copy_stored_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_copy_stored_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "destinationRecordingName") == 0) {
			args.destination_recording_name = (i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	if (ast_ari_recordings_copy_stored_parse_body(body, &args)) {
		ast_ari_response_alloc_failed(response);
		goto fin;
	}
	ast_ari_recordings_copy_stored(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
	case 409: /* A recording with the same name already exists on the system */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_stored_recording(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/stored/{recordingName}/copy\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/stored/{recordingName}/copy\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_get_live_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_get_live_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_get_live(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_live_recording(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_cancel_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_cancel_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_cancel(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}/stop.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_stop_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_stop_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_stop(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}/stop\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}/stop\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}/pause.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_pause_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_pause_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_pause(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
	case 409: /* Recording not in session */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}/pause\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}/pause\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}/pause.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_unpause_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_unpause_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_unpause(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
	case 409: /* Recording not in session */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}/pause\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}/pause\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}/mute.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_mute_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_mute_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_mute(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
	case 409: /* Recording not in session */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}/mute\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}/mute\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingName}/mute.
 * \param ser TCP/TLS session object
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param body
 * \param[out] response Response to the HTTP request.
 */
static void ast_ari_recordings_unmute_cb(
	struct ast_tcptls_session_instance *ser,
	struct ast_variable *get_params, struct ast_variable *path_vars,
	struct ast_variable *headers, struct ast_json *body, struct ast_ari_response *response)
{
	struct ast_ari_recordings_unmute_args args = {};
	struct ast_variable *i;
#if defined(AST_DEVMODE)
	int is_valid;
	int code;
#endif /* AST_DEVMODE */

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingName") == 0) {
			args.recording_name = (i->value);
		} else
		{}
	}
	ast_ari_recordings_unmute(headers, &args, response);
#if defined(AST_DEVMODE)
	code = response->response_code;

	switch (code) {
	case 0: /* Implementation is still a stub, or the code wasn't set */
		is_valid = response->message == NULL;
		break;
	case 500: /* Internal Server Error */
	case 501: /* Not Implemented */
	case 404: /* Recording not found */
	case 409: /* Recording not in session */
		is_valid = 1;
		break;
	default:
		if (200 <= code && code <= 299) {
			is_valid = ast_ari_validate_void(
				response->message);
		} else {
			ast_log(LOG_ERROR, "Invalid error response %d for /recordings/live/{recordingName}/mute\n", code);
			is_valid = 0;
		}
	}

	if (!is_valid) {
		ast_log(LOG_ERROR, "Response validation failed for /recordings/live/{recordingName}/mute\n");
		ast_ari_response_error(response, 500,
			"Internal Server Error", "Response validation failed");
	}
#endif /* AST_DEVMODE */

fin: __attribute__((unused))
	return;
}

/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_stored_recordingName_file = {
	.path_segment = "file",
	.callbacks = {
		[AST_HTTP_GET] = ast_ari_recordings_get_stored_file_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_stored_recordingName_copy = {
	.path_segment = "copy",
	.callbacks = {
		[AST_HTTP_POST] = ast_ari_recordings_copy_stored_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_stored_recordingName = {
	.path_segment = "recordingName",
	.is_wildcard = 1,
	.callbacks = {
		[AST_HTTP_GET] = ast_ari_recordings_get_stored_cb,
		[AST_HTTP_DELETE] = ast_ari_recordings_delete_stored_cb,
	},
	.num_children = 2,
	.children = { &recordings_stored_recordingName_file,&recordings_stored_recordingName_copy, }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_stored = {
	.path_segment = "stored",
	.callbacks = {
		[AST_HTTP_GET] = ast_ari_recordings_list_stored_cb,
	},
	.num_children = 1,
	.children = { &recordings_stored_recordingName, }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_live_recordingName_stop = {
	.path_segment = "stop",
	.callbacks = {
		[AST_HTTP_POST] = ast_ari_recordings_stop_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_live_recordingName_pause = {
	.path_segment = "pause",
	.callbacks = {
		[AST_HTTP_POST] = ast_ari_recordings_pause_cb,
		[AST_HTTP_DELETE] = ast_ari_recordings_unpause_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_live_recordingName_mute = {
	.path_segment = "mute",
	.callbacks = {
		[AST_HTTP_POST] = ast_ari_recordings_mute_cb,
		[AST_HTTP_DELETE] = ast_ari_recordings_unmute_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_live_recordingName = {
	.path_segment = "recordingName",
	.is_wildcard = 1,
	.callbacks = {
		[AST_HTTP_GET] = ast_ari_recordings_get_live_cb,
		[AST_HTTP_DELETE] = ast_ari_recordings_cancel_cb,
	},
	.num_children = 3,
	.children = { &recordings_live_recordingName_stop,&recordings_live_recordingName_pause,&recordings_live_recordingName_mute, }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings_live = {
	.path_segment = "live",
	.callbacks = {
	},
	.num_children = 1,
	.children = { &recordings_live_recordingName, }
};
/*! \brief REST handler for /api-docs/recordings.json */
static struct stasis_rest_handlers recordings = {
	.path_segment = "recordings",
	.callbacks = {
	},
	.num_children = 2,
	.children = { &recordings_stored,&recordings_live, }
};

static int unload_module(void)
{
	ast_ari_remove_handler(&recordings);
	return 0;
}

static int load_module(void)
{
	int res = 0;


	res |= ast_ari_add_handler(&recordings);
	if (res) {
		unload_module();
		return AST_MODULE_LOAD_DECLINE;
	}

	return AST_MODULE_LOAD_SUCCESS;
}

AST_MODULE_INFO(ASTERISK_GPL_KEY, AST_MODFLAG_DEFAULT, "RESTful API module - Recording resources",
	.support_level = AST_MODULE_SUPPORT_CORE,
	.load = load_module,
	.unload = unload_module,
	.requires = "res_ari,res_ari_model,res_stasis,res_stasis_recording",
);
