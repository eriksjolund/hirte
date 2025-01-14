/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#include <stdbool.h>

#include <systemd/sd-journal.h>

#include "libhirte/common/cfg.h"

#define HIRTE_LOG_TARGET_JOURNALD "journald"
#define HIRTE_LOG_TARGET_STDERR "stderr"

typedef enum LogLevel {
        LOG_LEVEL_DEBUG,
        LOG_LEVEL_INFO,
        LOG_LEVEL_WARN,
        LOG_LEVEL_ERROR,
        LOG_LEVEL_INVALID,
} LogLevel;

const char *log_level_to_string(LogLevel l);
LogLevel string_to_log_level(const char *l);


typedef int (*LogFn)(
                LogLevel lvl,
                const char *file,
                const char *line,
                const char *func,
                const char *msg,
                const char *data);

int hirte_log_to_journald_with_location(
                LogLevel lvl,
                const char *file,
                const char *line,
                const char *func,
                const char *msg,
                const char *data);
int hirte_log_to_stderr_with_location(
                LogLevel lvl,
                const char *file,
                const char *line,
                const char *func,
                const char *msg,
                const char *data);

void hirte_log_set_log_fn(LogFn log_fn);
void hirte_log_set_level(LogLevel level);
void hirte_log_set_quiet(bool is_quiet);

int hirte_log_init(struct config *config);

bool shouldLog(LogLevel lvl);

int hirte_log(LogLevel lvl,
              const char *file,
              const char *line,
              const char *func,
              const char *msg,
              const char *data);
int hirte_logf(LogLevel lvl, const char *file, const char *line, const char *func, const char *msgfmt, ...);
int hirte_log_with_data(
                LogLevel lvl,
                const char *file,
                const char *line,
                const char *func,
                const char *msg,
                const char *datafmt,
                ...);

#define hirte_log_debug(msg) hirte_log(LOG_LEVEL_DEBUG, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, "")
#define hirte_log_info(msg) hirte_log(LOG_LEVEL_INFO, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, "")
#define hirte_log_warn(msg) hirte_log(LOG_LEVEL_WARN, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, "")
#define hirte_log_error(msg) hirte_log(LOG_LEVEL_ERROR, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, "")

#define hirte_log_debugf(fmt, ...) \
        hirte_logf(LOG_LEVEL_DEBUG, __FILE__, _SD_STRINGIFY(__LINE__), __func__, fmt, __VA_ARGS__)
#define hirte_log_infof(fmt, ...) \
        hirte_logf(LOG_LEVEL_INFO, __FILE__, _SD_STRINGIFY(__LINE__), __func__, fmt, __VA_ARGS__)
#define hirte_log_warnf(fmt, ...) \
        hirte_logf(LOG_LEVEL_WARN, __FILE__, _SD_STRINGIFY(__LINE__), __func__, fmt, __VA_ARGS__)
#define hirte_log_errorf(fmt, ...) \
        hirte_logf(LOG_LEVEL_ERROR, __FILE__, _SD_STRINGIFY(__LINE__), __func__, fmt, __VA_ARGS__)

#define hirte_log_debug_with_data(msg, datafmt, ...) \
        hirte_log_with_data(                         \
                        LOG_LEVEL_DEBUG, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, datafmt, __VA_ARGS__)
#define hirte_log_info_with_data(msg, datafmt, ...) \
        hirte_log_with_data(                        \
                        LOG_LEVEL_INFO, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, datafmt, __VA_ARGS__)
#define hirte_log_warn_with_data(msg, datafmt, ...) \
        hirte_log_with_data(                        \
                        LOG_LEVEL_WARN, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, datafmt, __VA_ARGS__)
#define hirte_log_error_with_data(msg, datafmt, ...) \
        hirte_log_with_data(                         \
                        LOG_LEVEL_ERROR, __FILE__, _SD_STRINGIFY(__LINE__), __func__, msg, datafmt, __VA_ARGS__)
