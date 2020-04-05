/*
Cubesat Space Protocol - A small network-layer protocol designed for Cubesats
Copyright (C) 2012 GomSpace ApS (http://www.gomspace.com)
Copyright (C) 2012 AAUSAT3 Project (http://aausat3.space.aau.dk)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* #include <stdio.h> */
#include <csp/csp.h>

#include <devices/logger/logger.h>

/* Interfaces are stored in a linked list*/
static csp_iface_t * interfaces = NULL;

csp_iface_t * csp_iflist_get_by_name(const char *name) {
	csp_iface_t *ifc = interfaces;
	while(ifc) {
		if (strncmp(ifc->name, name, 10) == 0)
			break;
		ifc = ifc->next;
	}
	return ifc;
}

void csp_iflist_add(csp_iface_t *ifc) {

	/* Add interface to pool */
	if (interfaces == NULL) {
		/* This is the first interface to be added */
		interfaces = ifc;
		ifc->next = NULL;
	} else {
		/* One or more interfaces were already added */
		csp_iface_t * i = interfaces;
		while (i != ifc && i->next)
			i = i->next;

		/* Insert interface last if not already in pool */
		if (i != ifc && i->next == NULL) {
			i->next = ifc;
			ifc->next = NULL;
		}
	}

}

csp_iface_t * csp_iflist_get(void)
{
    return interfaces;
}

#ifdef CSP_DEBUG
static int csp_bytesize(char *buf, int len, unsigned long int n) {
	char postfix;
	double size;

	if (n >= 1048576) {
		size = n/1048576.0;
		postfix = 'M';
	} else if (n >= 1024) {
		size = n/1024.;
		postfix = 'K';
	} else {
		size = n;
		postfix = 'B';
 	}
 
	return snprintf(buf, len, "%.1f%c", size, postfix);
}

void csp_iflist_print(void) {
	csp_iface_t * i = interfaces;
	char txbuf[25], rxbuf[25];

	while (i) {
		csp_bytesize(txbuf, sizeof(txbuf), i->txbytes);
		csp_bytesize(rxbuf, sizeof(rxbuf), i->rxbytes);
		/* printf("%-10stx: %05"PRIu32" rx: %05"PRIu32" txe: %05"PRIu32" rxe: %05"PRIu32"\r\n" */
		/*        "          drop: %05"PRIu32" autherr: %05"PRIu32 " frame: %05"PRIu32"\r\n" */
		/*        "          txb: %"PRIu32" (%s) rxb: %"PRIu32" (%s) MTU: %u\r\n\r\n", */
		/*        i->name, i->tx, i->rx, i->tx_error, i->rx_error, i->drop, */
		/*        i->autherr, i->frame, i->txbytes, txbuf, i->rxbytes, rxbuf, i->mtu); */
        logger_print_event_from_module(LOGGER_INFO, LIBCSP_MODULE_NAME, "");
        logger_print_str(i->name);
        logger_print_msg("tx: ");
        logger_print_dec(i->tx);
        logger_print_msg(" rx: ");
        logger_print_dec(i->rx);
        logger_print_msg(" txe: ");
        logger_print_dec(i->tx_error);
        logger_print_msg(" rxe: ");
        logger_print_dec(i->rx_error);
        logger_new_line();
        logger_print_msg("\tdrop: ");
        logger_print_dec(i->drop);
        logger_print_msg(" autherr: ");
        logger_print_dec(i->autherr);
        logger_print_msg(" frame: ");
        logger_print_dec(i->frame);
        logger_print_msg(" frame: ");
        logger_new_line();
        logger_print_msg("\ttxb: ");
        logger_print_dec(i->txbytes);
        logger_print_msg(" (");
        logger_print_str(txbuf);
        logger_print_msg(") rxb: ");
        logger_print_dec(i->rxbytes);
        logger_print_msg(" (");
        logger_print_str(rxbuf);
        logger_print_msg(") MTU: ");
        logger_print_dec(i->mtu);
        logger_new_line();
		i = i->next;
	}

}
#endif

