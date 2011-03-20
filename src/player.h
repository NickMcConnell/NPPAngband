#ifndef INCLUDED_PLAYER_H
#define INCLUDED_PLAYER_H

/* File: player.h */

/*
 * Copyright (c) 2010 Jeff Greene, Diego Gonzalez
 *
 *
 *
 * This work is free software; you can redistribute it and/or modify it
 * under the terms of either:
 *
 * a) the GNU General Public License as published by the Free Software
 *    Foundation, version 2, or
 *
 * b) the "Angband licence":
 *    This software may be copied and distributed for educational, research,
 *    and not for profit purposes provided that this copyright and statement
 *    are included in all such copies.  Other copyrights may also apply.
 */


/*
 * Do not edit this file unless you know *exactly* what you are doing.
 *
 * Some of the values in this file were chosen to preserve game balance,
 * while others are hard-coded based on the format of old save-files, the
 * definition of arrays in various places, mathematical properties, fast
 * computation, storage limits, or the format of external text files.
 *
 * Changing some of these values will induce crashes or memory errors or
 * savefile mis-reads.  Most of the comments in this file are meant as
 * reminders, not complete descriptions, and even a complete knowledge
 * of the source may not be sufficient to fully understand the effects
 * of changing certain definitions.
 *
 * Lastly, note that the code does not always use the symbolic constants
 * below, and sometimes uses various hard-coded values that may not even
 * be defined in this file, but which may be related to definitions here.
 * This is of course bad programming practice, but nobody is perfect.
 *
 * For example, there are MANY things that depend on the screen being
 * 80x24, with the top line used for messages, the bottom line being
 * used for status, and exactly 22 lines used to show the dungeon.
 * Just because your screen can hold 46 lines does not mean that the
 * game will work if you try to use 44 lines to show the dungeon.
 *
 * You have been warned.
 */




/*
 * Maximum number of players spells
 */
#define PY_MAX_SPELLS 66

/*
 * Number of spells per book
 */
#define SPELLS_PER_BOOK 9

#define BOOKS_PER_REALM 9
#define MAGE_REALM		0
#define PRIEST_REALM	1
#define DRUID_REALM		2

/*Define the spell slot for the various classes*/
#define SPELL_STAT_SLOT \
		((cp_ptr->spell_book == TV_DRUID_BOOK) ? \
		 ((p_ptr->state.stat_ind[A_INT] + p_ptr->state.stat_ind[A_WIS]) / 2) : \
		 ((cp_ptr->spell_book == TV_MAGIC_BOOK) ? p_ptr->state.stat_ind[A_INT] : p_ptr->state.stat_ind[A_WIS]))


/*Magic for Beginners*/
#define SPELL_MAGIC_MISSILE             0
#define SPELL_DETECT_MONSTERS           1
#define SPELL_PHASE_DOOR                2
#define SPELL_LIGHT_AREA                3
#define SPELL_TREASURE_DETECTION        4
#define SPELL_CURE_LIGHT_WOUNDS         5
#define SPELL_OBJECT_DETECTION          6
#define SPELL_FIND_TRAPS_DOORS          7
#define SPELL_STINKING_CLOUD            8

/* Conjurings and Tricks */
#define SPELL_CONFUSE_MONSTER           9
#define SPELL_SHOCK_WAVE                10
#define SPELL_TRAP_DOOR_DESTRUCTION     11
#define SPELL_CURE_POISON               12
#define SPELL_SLEEP_MONSTER             13
#define SPELL_TELEPORT_SELF             14
#define SPELL_SPEAR_OF_LIGHT            15
#define SPELL_ICE_BOLT                  16
#define SPELL_WAIL_OF_THE_BANSHEE	65

/* Incantations and Illusions */
#define SPELL_SATISFY_HUNGER            18
#define SPELL_RECHARGE_ITEM_I           19
#define SPELL_TURN_STONE_TO_MUD         20
#define SPELL_SHARD_STORM               21
#define SPELL_POLYMORPH_OTHER           22
#define SPELL_IDENTIFY                  23
#define SPELL_DETECT_INVISIBLE          24
#define SPELL_HURRICANE                 25
#define SPELL_SLOW_MONSTER              26

/* Sorcery and Evocations */
#define SPELL_CALL_LIGHTNING            27
#define SPELL_TELEPORT_OTHER            28
#define SPELL_HASTE_SELF                29
#define SPELL_MASS_SLEEP                30
#define SPELL_WATER_BOLT                31
#define SPELL_DETECT_ENCHANTMENT        32
#define SPELL_MASS_IDENTIFY				64

/* Resistances of Scarabtarices */
#define SPELL_RESIST_COLD               33
#define SPELL_RESIST_FIRE               34
#define SPELL_RESIST_POISON             35
#define SPELL_RESISTANCE                36
#define SPELL_SHIELD                    37

/* Raal's Tome of Destruction */
#define SPELL_NOVA                      38
#define SPELL_REND_SOUL                 39
#define SPELL_PRISMATIC_SPRAY           17
#define SPELL_CLOUD_KILL                40
#define SPELL_ICE_STORM                 41
#define SPELL_PLASMA_BOLT               42
#define SPELL_METEOR_STORM              43
#define SPELL_RIFT                      44

/* Mordenkainen's Escapes */
#define SPELL_DOOR_CREATION             45
#define SPELL_STAIR_CREATION            46
#define SPELL_TELEPORT_LEVEL            47
#define SPELL_WORD_OF_RECALL            48
#define SPELL_RUNE_OF_PROTECTION        49
#define SPELL_FLIGHT					50

/* Tenser's transformations */
#define SPELL_BERSERKER                 51
#define SPELL_ENCHANT_ARMOR             52
#define SPELL_ENCHANT_WEAPON            53
#define SPELL_RECHARGE_ITEM_II          54
#define SPELL_ELEMENTAL_BRAND           55


/* Kelek's Grimoire of Power */
#define SPELL_EARTHQUAKE                56
#define SPELL_BEDLAM                    57
#define SPELL_BANISHMENT                58
#define SPELL_WORD_OF_DESTRUCTION       59
#define SPELL_MASS_BANISHMENT           60
#define SPELL_DARKNESS_STORM            61
#define SPELL_MANA_BOLT                 62
#define SPELL_MANA_STORM                63


/* Beginners Handbook */
#define PRAYER_DETECT_EVIL              0
#define PRAYER_CURE_LIGHT_WOUNDS        1
#define PRAYER_BLESS                    2
#define PRAYER_REMOVE_FEAR              3
#define PRAYER_CALL_LIGHT               4
#define PRAYER_FIND_TRAPS_DOORS_STAIRS  5
#define PRAYER_SHOCK_BOLT	        6
#define PRAYER_SLOW_POISON              7

/* Words of Wisdom */
#define PRAYER_SCARE_MONSTER            8
#define PRAYER_PORTAL                   9
#define PRAYER_CURE_SERIOUS_WOUNDS     10
#define PRAYER_CHANT                   11
#define PRAYER_SANCTUARY               12
#define PRAYER_SATISFY_HUNGER          13
#define PRAYER_REMOVE_CURSE            14
#define PRAYER_RESIST_HEAT_COLD        15

/* Chants and Blessings */
#define PRAYER_NEUTRALIZE_POISON       16
#define PRAYER_ORB_OF_DRAINING         17
#define PRAYER_CURE_CRITICAL_WOUNDS    18
#define PRAYER_SENSE_INVISIBLE         19
#define PRAYER_PROTECTION_FROM_EVIL    20
#define PRAYER_EARTHQUAKE              21
#define PRAYER_SENSE_SURROUNDINGS      22
#define PRAYER_CURE_MORTAL_WOUNDS      23
#define PRAYER_TURN_UNDEAD             24

/* Exorcism and Dispelling */
#define PRAYER_PRAYER                  25
#define PRAYER_SUN_BEAM                26
#define PRAYER_HEAL                    27
#define PRAYER_DISPEL_EVIL             28
#define PRAYER_GLYPH_OF_WARDING        29
#define PRAYER_HOLY_WORD               30

/* Godly Insights */
#define PRAYER_DETECT_MONSTERS         31
#define PRAYER_DETECTION               32
#define PRAYER_PERCEPTION              33
#define PRAYER_PROBING                 34
#define PRAYER_CLAIRVOYANCE            35
#define PRAYER_MASS_IDENTIFY		   58

/* Purifications and Healing */
#define PRAYER_CURE_SERIOUS_WOUNDS2    36
#define PRAYER_CURE_MORTAL_WOUNDS2     37
#define PRAYER_HEALING                 38
#define PRAYER_RESTORATION             39
#define PRAYER_REMEMBRANCE             40

/* Wrath of God */
#define PRAYER_SUN_BURST               41
#define PRAYER_DISPEL_EVIL2            42
#define PRAYER_BANISH_EVIL             43
#define PRAYER_WORD_OF_DESTRUCTION     44
#define PRAYER_JUDGEMENT_OF_MANDOS      45

/* Holy Infusions */
#define PRAYER_UNBARRING_WAYS          46
#define PRAYER_RECHARGING              47
#define PRAYER_DISPEL_CURSE            48
#define PRAYER_ENCHANT_WEAPON          49
#define PRAYER_ENCHANT_ARMOUR          50
#define PRAYER_ELEMENTAL_BRAND         51

/* Ethereal openings */
#define PRAYER_BLINK                   52
#define PRAYER_TELEPORT_SELF           53
#define PRAYER_TELEPORT_OTHER          54
#define PRAYER_TELEPORT_LEVEL          55
#define PRAYER_WORD_OF_RECALL          56
#define PRAYER_ALTER_REALITY           57


/* Call of the Wild */
#define DRUID_ACID_BOLT                  0
#define DRUID_CURE_LIGHT_WOUNDS          1
#define DRUID_DETECT_LIFE              	 2
#define DRUID_CALL_LIGHT               	 3
#define DRUID_FIND_TRAPS_DOORS         	 4
#define DRUID_SLOW_POISON                5
#define DRUID_POISON_CLOUD             	 6
#define DRUID_NATURAL_ESCAPE           	 7
#define DRUID_BARKSKIN		             8

/* Environmental Adjurations */
#define DRUID_NOURISHMENT	             9
#define DRUID_TURN_STONE_TO_MUD        	10
#define DRUID_FROST_BEAM               	11
#define DRUID_CURE_POISON              	12
#define DRUID_TRAP_DOOR_DESTRUCTION    	13
#define DRUID_RESIST_HEAT_COLD         	14
#define DRUID_SPEAR_OF_LIGHT           	15
#define DRUID_FIRE_BEAM               	16
#define DRUID_STERILIZE					17

/* Commanding Nature */
#define DRUID_EXTINGUISH		       	18
#define DRUID_CLEAR_AREA		       	19
#define DRUID_CURE_CRITICAL_WOUNDS    	20
#define DRUID_IDENTIFY             		21
#define DRUID_CLEAR_AIR              	22
#define DRUID_DETECT_TERRAIN	      	23
#define DRUID_EARTHQUAKE 	     		24
#define DRUID_LIFE_DRAIN_BURST		 	26

/* Lore of Engagement */
#define DRUID_ELEMENTAL_BRAND          	28
#define DRUID_FROST_BALL              	29
#define DRUID_HEAL                    	30
#define DRUID_DISPEL_LIFE				31
#define DRUID_FIRE_BALL               	32
#define DRUID_DRAIN_LIFE_ARC			33
#define DRUID_MASS_IDENTIFY				34

/* Radagast's Protections */
#define DRUID_RESIST_ELEC               35
#define DRUID_RESIST_ACID               36
#define DRUID_RESIST_POISON             37
#define DRUID_RESISTANCE                38
#define DRUID_HASTE_SELF          		39
#define DRUID_GLACIER			        40

/* Melian's Reformations */
#define DRUID_FLICKER			    	41
#define DRUID_WORD_OF_RECALL	     	42
#define DRUID_HEALING                 	43
#define DRUID_RESTORATION             	44
#define DRUID_REMEMBRANCE             	45
#define DRUID_SANDSTORM	         	25

/* Arda's Habitats */
#define DRUID_NATIVE_SAND				46
#define DRUID_NATIVE_MUD				47
#define DRUID_NATIVE_WATER				48
#define DRUID_NATIVE_OIL				49
#define DRUID_NATIVE_LAVA				50
#define DRUID_CHANNEL_LIGHTNING			64

/* Natural Infusions */
#define DRUID_DISPEL_CURSE              52
#define DRUID_RECHARGE_ITEM             53
#define DRUID_BRAND_AMMUNITION          54
#define DRUID_ENCHANT_ARMOUR            55
#define DRUID_BRAND_WEAPON              56

/* Nature's Fury */
#define DRUID_WATER_CHAIN				58
#define DRUID_CALL_HUORNS				60
#define DRUID_MASTER_ELEMENTS			62
#define DRUID_STEAL_POWERS				63



/*
 * Flags for player_type.spell_flags[]
 */
#define PY_SPELL_LEARNED    0x01 /* Spell has been learned */
#define PY_SPELL_WORKED     0x02 /* Spell has been successfully tried */
#define PY_SPELL_FORGOTTEN  0x04 /* Spell has been forgotten */
#define PY_SPELL_IRONMAN	0x08 /* Spell is for ironman games only. */


/*
 * Player constants
 */
#define PY_MAX_EXP	99999999L	/* Maximum exp */
#define PY_MAX_GOLD	999999999L	/* Maximum gold */
#define PY_MAX_LEVEL	50		/* Maximum level */

/*
 * Player "food" crucial values
 */
#define PY_FOOD_UPPER   20000   /* Upper limit on food counter */
#define PY_FOOD_MAX		15000	/* Food value (Bloated) */
#define PY_FOOD_FULL	10000	/* Food value (Normal) */
#define PY_FOOD_ALERT	2000	/* Food value (Hungry) */
#define PY_FOOD_WEAK	1000	/* Food value (Weak) */
#define PY_FOOD_FAINT	500		/* Food value (Fainting) */
#define PY_FOOD_STARVE	100		/* Food value (Starving) */

/*
 * Player regeneration constants
 */
#define PY_REGEN_NORMAL		197		/* Regen factor*2^16 when full */
#define PY_REGEN_WEAK		98		/* Regen factor*2^16 when weak */
#define PY_REGEN_FAINT		33		/* Regen factor*2^16 when fainting */
#define PY_REGEN_HPBASE		1442	/* Min amount hp regen*2^16 */
#define PY_REGEN_MNBASE		524		/* Min amount mana regen*2^16 */


/* Flags for the detect spell */
#define DETECT_INVISIBLE	0x0001 	/* Detect Invisible Monsters*/
#define DETECT_EVIL			0x0002 	/* Detect Evil Monsters*/
#define DETECT_LIFE			0x0004 	/* Detect Living Monsters */
#define DETECT_MONSTERS		0x0008 	/* Detect (visible) Monsters */
#define DETECT_GOLD			0x0010 	/* Detect Gold */
#define DETECT_TREASURE		0x0020 	/* Detect Treasure */
#define DETECT_ENCHANTMENT	0x0040 	/* Detect Enchanted Objects*/
#define DETECT_OBJECTS		0x0080 	/* Detect Objects */
#define DETECT_DOORS		0x0100 	/* Detect Doors */
#define DETECT_STAIRS		0x0200 	/* Detect Stairs */
#define DETECT_TERRAIN		0x0400 	/* Detect Terrain */
#define DETECT_TRAPS		0x0800 	/* Detect Traps */
#define DETECT_MAP			0x1000 	/* Magic Mapping */
#define DETECT_XXXX2		0x2000 	/* Unused */
#define DETECT_XXXX4		0x4000 	/* Unused */
#define DETECT_XXXX8		0x8000 	/* Unused */

#define DETECT_ALL_TREASURE 		(DETECT_GOLD | DETECT_TREASURE)
#define DETECT_DOORS_STAIRS  		(DETECT_DOORS | DETECT_STAIRS)
#define DETECT_ALL_MONSTERS 		(DETECT_MONSTERS | DETECT_INVISIBLE)
#define DETECT_DOORS_STAIRS_TRAPS  	(DETECT_DOORS_STAIRS | DETECT_TRAPS)
#define DETECT_ENLIGHTENMENT 		(DETECT_DOORS_STAIRS | DETECT_TRAPS | \
										DETECT_ALL_TREASURE | DETECT_OBJECTS)
#define DETECT_ALL					(DETECT_DOORS_STAIRS_TRAPS | DETECT_ALL_TREASURE | \
										DETECT_OBJECTS | DETECT_ALL_MONSTERS)

#define DETECT_RADIUS		40


/*
 * Maximum number of "normal" pack slots, and the index of the "overflow"
 * slot, which can hold an item, but only temporarily, since it causes the
 * pack to "overflow", dropping the "last" item onto the ground.  Since this
 * value is used as an actual slot, it must be less than "INVEN_WIELD" (below).
 * Note that "INVEN_PACK" is probably hard-coded by its use in savefiles, and
 * by the fact that the screen can only show 23 items plus a one-line prompt.
 */
#define INVEN_PACK		23

/*
 * Like the previous but takes into account the (variably full quiver).
 */
#define INVEN_MAX_PACK  (INVEN_PACK - p_ptr->quiver_slots)

/*
 * Indexes used for various "equipment" slots (hard-coded by savefiles, etc).
 */
#define INVEN_WIELD		24
#define INVEN_BOW       25
#define INVEN_LEFT      26
#define INVEN_RIGHT     27
#define INVEN_NECK      28
#define INVEN_LIGHT      29
#define INVEN_BODY      30
#define INVEN_OUTER     31
#define INVEN_ARM       32
#define INVEN_HEAD      33
#define INVEN_HANDS     34
#define INVEN_FEET      35

/*
 * Total number of inventory slots (hard-coded).
 */
#define INVEN_TOTAL		36


/*
 *Quiver
 */
#define QUIVER_START 37
#define QUIVER_SIZE  10
#define QUIVER_END   47

#define ALL_INVEN_TOTAL 47


/*
 * Used to determine if a slot is a quiver slot.
 */
#define IS_QUIVER_SLOT(slot) \
(((slot) >= QUIVER_START) && ((slot) < QUIVER_END))


/*
 * Timed effects
 */
enum
{
	TMD_FAST = 0,
	TMD_SLOW,
	TMD_BLIND,
	TMD_PARALYZED,
	TMD_CONFUSED,
	TMD_AFRAID,
	TMD_IMAGE,
	TMD_POISONED,
	TMD_CUT,
	TMD_STUN,
	TMD_PROTEVIL,
	TMD_INVULN,
	TMD_HERO,
	TMD_SHERO,
	TMD_SHIELD,
	TMD_BLESSED,
	TMD_SINVIS,
	TMD_SINFRA,
	TMD_OPP_ACID,
	TMD_OPP_ELEC,
	TMD_OPP_FIRE,
	TMD_OPP_COLD,
	TMD_OPP_POIS,
	TMD_FLYING,
	TMD_NAT_LAVA,
	TMD_NAT_OIL,
	TMD_NAT_SAND,
	TMD_NAT_TREE,
	TMD_NAT_WATER,
	TMD_NAT_MUD,
	TMD_SLAY_ELEM,
	TMD_CALL_HOURNS,

	TMD_MAX
};


/*
 * Skill indexes
 */
enum
{
	SKILL_DISARM,			/* Skill: Disarming */
	SKILL_DEVICE,			/* Skill: Magic Devices */
	SKILL_SAVE,				/* Skill: Saving throw */
	SKILL_STEALTH,			/* Skill: Stealth factor */
	SKILL_SEARCH,			/* Skill: Searching ability */
	SKILL_SEARCH_FREQUENCY,	/* Skill: Searching frequency */
	SKILL_TO_HIT_MELEE,		/* Skill: To hit (normal) */
	SKILL_TO_HIT_BOW,		/* Skill: To hit (shooting) */
	SKILL_TO_HIT_THROW,		/* Skill: To hit (throwing) */
	SKILL_DIGGING,			/* Skill: Digging */

	SKILL_MAX
};


/*
 * Indexes of the various "stats" (hard-coded by savefiles, etc).
 */
enum
{
	A_STR = 0,
	A_INT,
	A_WIS,
	A_DEX,
	A_CON,
	A_CHR,

	A_MAX
};

/*** Player flags ***/

/*
 * Bit flags for the "p_ptr->notice" variable
 */
#define PN_COMBINE		0x00000001L	/* Combine the pack */
#define PN_REORDER		0x00000002L	/* Reorder the pack */
#define PN_AUTOINSCRIBE	0x00000004L	/* Autoinscribe items */
#define PN_SORT_QUIVER	0x00000008L	/* Quiver Sort */
#define PN_QUEST_REMAIN	0x00000010L	/* # of remaining monsters */
#define PN_MON_MESSAGE	0x00000020L	/* flush monster messages */

/* xxx (many) */


/*
 * Bit flags for the "p_ptr->update" variable
 */

#define PU_FLOW_LAVA	ELEMENT_LAVA	/* Update flow through ice */
#define PU_FLOW_ICE		ELEMENT_ICE		/* Update flow through ice */
#define PU_FLOW_OIL		ELEMENT_OIL		/* Update flow through oil */
#define PU_FLOW_FIRE	ELEMENT_FIRE	/* Update flow up to fire */
#define PU_FLOW_SAND	ELEMENT_SAND	/* Update flow through sand */
#define PU_FLOW_FOREST	ELEMENT_FOREST	/* Update flow through forest */
#define PU_FLOW_WATER	ELEMENT_WATER	/* Update flow through water */
#define PU_FLOW_ACID	ELEMENT_ACID	/* Update flow up to acid */
#define PU_FLOW_MUD		ELEMENT_MUD		/* Update flow up to acid */
#define PU_FLOW_DOORS		0x00000400L			/* Update flow through doors */
#define PU_FLOW_NO_DOORS	0x00000800L	/* Update flow up to doors */
#define PU_FLOW_FLYING		0x00001000L	/* Update flow for flying creatures */
#define PU_FLOW_PASS_WALLS     0x00002000L     /* Update flow for creatures who pass through or kill walls */
#define PU_FLOW_NO_DOORS_SPECIAL       0x00004000L /* Update the "doorless" versions of the flows */

#define PU_NATIVE		0x00100000L	/* Calculate nativity */
#define PU_STEALTH		0x00200000L	/* Calculate bonuses */
#define PU_BONUS		0x00400000L	/* Calculate bonuses */
#define PU_TORCH		0x00800000L	/* Calculate torch radius */
#define PU_HP			0x01000000L	/* Calculate chp and mhp */
#define PU_MANA			0x02000000L	/* Calculate csp and msp */
#define PU_SPELLS		0x04000000L	/* Calculate spells */
#define PU_FORGET_VIEW	0x08000000L	/* Forget field of view */
#define PU_UPDATE_VIEW	0x10000000L	/* Update field of view */
#define PU_MONSTERS		0x20000000L	/* Update monsters */
#define PU_DISTANCE		0x40000000L	/* Update distances */
#define PU_PANEL		0x80000000L	/* Update panel */



/*
 * Bit flags for the "p_ptr->redraw" variable
 */
#define PR_MISC			0x00000001L	/* Display Race/Class */
#define PR_TITLE		0x00000002L	/* Display Title */
#define PR_LEV			0x00000004L	/* Display Level */
#define PR_EXP			0x00000008L	/* Display Experience */
#define PR_STATS		0x00000010L	/* Display Stats */
#define PR_ARMOR		0x00000020L	/* Display Armor */
#define PR_HP			0x00000040L	/* Display Hitpoints */
#define PR_MANA			0x00000080L	/* Display Mana */
#define PR_GOLD			0x00000100L	/* Display Gold */
#define PR_DEPTH		0x00000200L	/* Display Depth */
#define PR_QUEST_ST		0x00000400L	/* Display quest status */
#define PR_HEALTH		0x00000800L	/* Display Monster Health Bar */
#define PR_FEELING		0x00001000L	/* Display Level Feeling */
#define PR_OBJECT		0x00002000L	/* Display object recall */
#define PR_MONSTER		0x00004000L	/* Display monster recall */
#define PR_MON_MANA		0x00008000L	/* Display Monster Mana Bar */
#define PR_MESSAGE		0x00010000L	/* Display messages */
#define PR_EQUIP		0x00020000L	/* Display equip/inven */
#define PR_INVEN		0x00040000L	/* Display inven/equip */
#define PR_STATE		0x00080000L	/* Display Extra (State) */
#define PR_STATUS		0x00100000L	/* Display Status */
#define PR_SPEED		0x00200000L	/* Display Extra (Speed) */
#define PR_STUDY		0x00400000L	/* Display Extra (Study) */
#define PR_RESIST		0X00800000L	/* Display Resistances */
#define PR_BUTTONS      0x01000000L /* Display mouse buttons */
#define PR_DTRAP		0x02000000L /* Trap Detection Indicator */
#define PR_ITEMLIST     0x04000000L /* Display item list */
#define PR_MAP			0x08000000L	/* Display Map */
#define PR_MONLIST		0x10000000L	/* Display monster list */
#define PR_FEATURE		0x20000000L	/* Display feature */
#define PR_PLAYER_NATIVE 0x40000000L	/* Returns whether the terrain is native or not */
#define PR_UNUSED2		0x80000000L	/* Unused */
/* xxx (many) */
/* Display Basic Info */
#define PR_BASIC \
	(PR_MISC | PR_TITLE | PR_STATS | PR_LEV |\
	 PR_EXP | PR_GOLD | PR_ARMOR | PR_HP | PR_FEELING | \
	 PR_MANA | PR_DEPTH | PR_HEALTH | PR_SPEED | PR_QUEST_ST)

/* Display Extra Info */
#define PR_EXTRA \
	(PR_STATUS | PR_STATE | PR_STUDY)

/*Number of possible display options*/
#define	 MAX_DISPLAY_OPTIONS 17

/*
 * Bit flags for the "p_ptr->window" variable (etc)
 */
#define PW_INVEN            0x00000001L /* Display inven/equip */
#define PW_EQUIP            0x00000002L /* Display equip/inven */
#define PW_PLAYER_0         0x00000004L /* Display player (basic) */
#define PW_PLAYER_1         0x00000008L /* Display player (extra) */
#define PW_PLAYER_2         0x00000010L /* Display player (compact) */
#define PW_MAP              0x00000020L /* Display dungeon map */
#define PW_MESSAGE          0x00000040L /* Display messages */
#define PW_OVERHEAD         0x00000080L /* Display overhead view */
#define PW_MONSTER          0x00000100L /* Display monster recall */
#define PW_OBJECT           0x00000200L /* Display object recall */
#define PW_MONLIST          0x00000400L /* Display monster list */
#define PW_STATUS           0x00000800L /* Display Status */
#define PW_ITEMLIST	        0x00001000L /* Display item list */
#define PW_FEATURE		    0x00002000L /* Display feature status */
#define PW_BORG_1           0x00004000L /* Display borg messages */
#define PW_BORG_2           0x00008000L /* Display borg status */


#define PW_MAX_FLAGS		16


/*Player Native Flags*/
#define P_NATIVE_LAVA 	ELEMENT_LAVA
#define P_NATIVE_ICE 	ELEMENT_ICE
#define P_NATIVE_OIL 	ELEMENT_OIL
#define P_NATIVE_FIRE 	ELEMENT_FIRE
#define P_NATIVE_SAND 	ELEMENT_SAND
#define P_NATIVE_FOREST ELEMENT_FOREST
#define P_NATIVE_WATER 	ELEMENT_WATER
#define P_NATIVE_ACID 	ELEMENT_ACID
#define P_NATIVE_MUD 	ELEMENT_MUD

#define NUM_NATIVE 9


/*
 * Modes for the "do_spell" function
 */
#define MODE_SPELL_CAST    1
#define MODE_SPELL_NAME    2
#define MODE_SPELL_DESC    3




#define LEV_EXTRA_COMBAT 	26
#define LEV_BRAVERY 	30
#define LEV_RES_POIS	35

/*** Class flags ***/

#define CF_EXTRA_SHOT		0x00000001L	/* Extra shots when using sling*/
#define CF_BRAVERY_30		0x00000002L	/* Gains resist fear at plev 30 */
#define CF_BLESS_WEAPON		0x00000004L	/* Requires blessed/hafted weapons */
#define CF_CUMBER_GLOVE		0x00000008L	/* Gloves disturb spellcasting */
#define CF_ZERO_FAIL		0x00000010L /* Fail rates can reach 0% */
#define CF_BEAM				0x00000020L /* Higher chance of spells beaming */
#define CF_CHOOSE_SPELLS	0x00000040L	/* Allow choice of spells */
#define CF_PSEUDO_ID_HEAVY	0x00000080L /* Allow heavy pseudo-id */
#define CF_PSEUDO_ID_IMPROV	0x00000100L /* Pseudo-id improves quicker with player-level */
#define CF_ROGUE_COMBAT		0x00000200L /* Permits such as steal & critical hit*/
#define CF_EXTRA_ARROW		0x00000400L /* Extra arrow when using bow*/
#define CF_SET_TRAPS		0x00000800L /* Can set traps for monsters to fall into*/
#define CF_EXTRA_ATTACK		0x00001000L /* extra attack at level 26*/
#define CF_BRIGAND_COMBAT		0x00002000L /* Brigand combat */
#define CF_CFXXX15			0x00004000L
#define CF_CFXXX16			0x00008000L
#define CF_CFXXX17			0x00010000L
#define CF_CFXXX18			0x00020000L
#define CF_CFXXX19			0x00040000L
#define CF_CFXXX20			0x00080000L
#define CF_CFXXX21			0x00100000L
#define CF_CFXXX22			0x00200000L
#define CF_CFXXX23			0x00400000L
#define CF_CFXXX24			0x00800000L
#define CF_CFXXX25			0x01000000L
#define CF_CFXXX26			0x02000000L
#define CF_CFXXX27			0x04000000L
#define CF_CFXXX28			0x08000000L
#define CF_CFXXX29			0x10000000L
#define CF_CFXXX30			0x20000000L
#define CF_CFXXX31			0x40000000L
#define CF_CFXXX32			0x80000000L




/* flags for q_flags */
#define QFLAG_STARTED   	0x01
#define QFLAG_EXTRA_LEVEL   0x02

#endif /*INCLUDED_PLAYER_H*/

