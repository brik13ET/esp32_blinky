#include <stdio.h>

#include <esp_log.h>
#include <driver/gptimer.h>
#include "driver/gpio.h"

uint8_t led;
gptimer_handle_t tim1;

bool gptimerAlarmCb(gptimer_handle_t *, gptimer_alarm_event_data_t *, void *) {
	gpio_set_level(GPIO_NUM_2, led == 0);
	led = !led;
	return true;
}

void app_main(void) {
	gpio_config(
			&(gpio_config_t)
					{
							.mode = GPIO_MODE_OUTPUT,
							.pin_bit_mask = GPIO_NUM_2,
							.intr_type = GPIO_INTR_HIGH_LEVEL,
							.pull_down_en = GPIO_PULLDOWN_ENABLE
					}
	);
	gptimer_new_timer(&(gptimer_config_t) {
			.clk_src = GPTIMER_CLK_SRC_DEFAULT,
			.direction = GPTIMER_COUNT_DOWN,
			.resolution_hz = 1000
	}, &tim1);
	gptimer_set_alarm_action(tim1, &(gptimer_alarm_config_t) {
			                         .alarm_count = 500,
			                         .reload_count = 500,
			                         .flags.auto_reload_on_alarm = 1
	                         }
	);
	gptimer_register_event_callbacks(tim1, gptimerAlarmCb, &led);
	gptimer_enable(tim1);
	while (1);
}
