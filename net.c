#include "net.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "platform.h"
#include "util.h"

static struct net_device *devices;

struct net_device *net_device_alloc(void) {
    struct net_device *dev;
    dev = memory_alloc(sizeof(*dev));
    if (!dev) {
        errorf("memory_alloc() failure");
        return NULL;
    }
    return dev;
}

int net_device_register(struct net_device *dev) {
    static unsigned int index = 0;

    dev->index = index++;
    snprintf(dev->name, sizeof(dev->name), "net%d", dev->index);
    dev->next = devices;
    devices = dev;
    infof("registerd, dev=%s, type=0x%04x", dev->name, dev->type);
    return 0;
}

static int net_device_open(struct net_device *dev) {}

static int net_device_close(struct net_device *dev) {}

int net_device_output(struct net_device *dev, uint16_t type,
                      const uint8_t *data, size_t len, const void *dst) {}

int net_input_handler(uint16_t type, const uint8_t *data, size_t len,
                      struct net_device *dev) {}

int net_run(void) {}

void net_shutdown(void) {}

int net_init(void) {}