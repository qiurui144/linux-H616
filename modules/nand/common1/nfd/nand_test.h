/*
 * nand_test.h for  SUNXI NAND .
 *
 * Copyright (C) 2016 Allwinner.
 *
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */
#ifndef _NAND_TEST_H_
#define _NAND_TEST_H_

#include "nand_blk.h"
#include "nand_dev.h"

extern int debug_data;

extern uint32 gc_one(void *zone, uint16 invalid_page_count);
extern uint32 gc_all(void *zone, uint16 invalid_page_count);
extern uint32 prio_gc_one(void *zone, uint16 block, uint32 flag);
extern void print_nftl_zone(void *zone);
extern void print_free_list(void *zone);
extern void print_block_invalid_list(void *zone);
extern uint32 nftl_set_zone_test(void *_zone, uint32 num);
extern int nand_dbg_phy_read(unsigned short nDieNum, unsigned short nBlkNum,
			     unsigned short nPage);
extern int nand_dbg_zone_phy_read(void *zone, uint16 block, uint16 page);
extern int nand_dbg_zone_erase(void *zone, uint16 block, uint16 erase_num);
extern int nand_dbg_zone_phy_write(void *zone, uint16 block, uint16 page);
extern int nand_dbg_phy_write(unsigned short nDieNum, unsigned short nBlkNum,
			      unsigned short nPage);
extern int nand_dbg_phy_erase(unsigned short nDieNum, unsigned short nBlkNum);
extern int _dev_nand_read2(char *name, __u32 start_sector, __u32 len,
			   unsigned char *buf);
extern void nand_phy_test(void);
extern int nand_check_table(void *zone);

extern int _dev_nand_read(struct _nand_dev *nand_dev, __u32 start_sector,
			  __u32 len, unsigned char *buf);
extern int _dev_nand_write(struct _nand_dev *nand_dev, __u32 start_sector,
			   __u32 len, unsigned char *buf);
extern int _dev_flush_write_cache(struct _nand_dev *nand_dev, __u32 num);
extern struct _nand_dev *_get_nand_dev_by_name(char *name);

struct task_struct *p_udisk_test_thread;
int udisk_test_thread_running;
struct _nand_dev *udisk_test_nand_dev;

unsigned char *udisk_test_buf;     /*128K*/
unsigned char *udisk_test_mapping; /* (500*1024) * 8 byte*/

#define MAX_PTR_PER_TEST (500 * 1024)
#endif
