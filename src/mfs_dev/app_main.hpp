/**
 * @file app_main.hpp
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief アプリメインヘッダー
 * @version 0.1
 * @date 2024-11-17
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef APP_MAIN_HPP
#define APP_MAIN_HPP

#include "common.hpp"
#include "drv_timer.hpp"
#include "drv_7segled.hpp"
#include "mfs.hpp"

void app_main_init(void);
void app_main(void);

#endif /* APP_MAIN_HPP */