#ifndef INCLUDED_MONSTER_H
#define INCLUDED_MONSTER_H

/* File: monster.h */

/*
 * Copyright (c) 2010 Jeff Greene, Diego Gonzalez
 *
 * This software may be copied and distributed for educational, research,
 * and not for profit purposes provided that this copyright and statement
 * are included in all such copies.  Other copyrights may also apply.
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
 * Some bit-flags for the "smart" field".
 *
 * Most of these map to the "TR2_xxx" flags.
 */
#define SM_OPP_ACID		0x00000001
#define SM_OPP_ELEC		0x00000002
#define SM_OPP_FIRE		0x00000004
#define SM_OPP_COLD		0x00000008
#define SM_OPP_POIS		0x00000010
#define SM_OPP_XXX1		0x00000020
#define SM_OPP_XXX2		0x00000040
#define SM_GOOD_SAVE	0x00000080
#define SM_PERF_SAVE	0x00000100
#define SM_IMM_FREE		0x00000200
#define SM_IMM_MANA		0x00000400
#define SM_IMM_ACID		0x00000800
#define SM_IMM_ELEC		0x00001000
#define SM_IMM_FIRE		0x00002000
#define SM_IMM_COLD		0x00004000
#define SM_IMM_POIS		0x00008000
#define SM_RES_ACID		0x00010000
#define SM_RES_ELEC		0x00020000
#define SM_RES_FIRE		0x00040000
#define SM_RES_COLD		0x00080000
#define SM_RES_POIS		0x00100000
#define SM_RES_FEAR		0x00200000
#define SM_RES_LIGHT	0x00400000
#define SM_RES_DARK		0x00800000
#define SM_RES_BLIND	0x01000000
#define SM_RES_CONFU	0x02000000
#define SM_RES_SOUND	0x04000000
#define SM_RES_SHARD	0x08000000
#define SM_RES_NEXUS	0x10000000
#define SM_RES_NETHR	0x20000000
#define SM_RES_CHAOS	0x40000000
#define SM_RES_DISEN	0x80000000



/*
 * Legal restrictions for "summon_specific()"
 */
#define SUMMON_ANT	        11
#define SUMMON_SPIDER       12
#define SUMMON_HOUND        13
#define SUMMON_HYDRA        14
#define SUMMON_AINU	        15
#define SUMMON_DEMON        16
#define SUMMON_UNDEAD       17
#define SUMMON_DRAGON       18
/* xxx */
#define SUMMON_HI_DEMON     26
#define SUMMON_HI_UNDEAD    27
#define SUMMON_HI_DRAGON    28
/* xxx */
#define SUMMON_WRAITH       31
#define SUMMON_UNIQUE       32
#define SUMMON_HI_UNIQUE    33
#define SUMMON_KIN          34

#define SUMMON_ANIMAL      50
#define SUMMON_BERTBILLTOM 51
#define SUMMON_THIEF       53

#define SUMMON_INDEX       60

/*
 * Bit flags for the "monster_desc" function
 */
#define MDESC_OBJE		0x01	/* Objective (or Reflexive) */
#define MDESC_POSS		0x02	/* Possessive (or Reflexive) */
#define MDESC_IND1		0x04	/* Indefinites for hidden monsters */
#define MDESC_IND2		0x08	/* Indefinites for visible monsters */
#define MDESC_PRO1		0x10	/* Pronominalize hidden monsters */
#define MDESC_PRO2		0x20	/* Pronominalize visible monsters */
#define MDESC_HIDE		0x40	/* Assume the monster is hidden */
#define MDESC_SHOW		0x80	/* Assume the monster is visible */



#define MONSTER_BLOW_MAX 4

/*used to populate the mon_power_ave table*/
#define CREATURE_NON_UNIQUE	0
#define CREATURE_UNIQUE 	1
#define CREATURE_TYPE_MAX	2


/*columns for the spell cost or damage flags*/
#define COL_SPELL_MANA_COST		0
#define COL_SPELL_DAM_MULT		1
#define COL_SPELL_DAM_DIV		2
#define COL_SPELL_DAM_VAR		3
#define COL_SPELL_BEST_RANGE	4



/*** Monster blow constants ***/

#define RBM_HIT           1
#define RBM_TOUCH         2
#define RBM_PUNCH         3
#define RBM_KICK          4
#define RBM_CLAW          5
#define RBM_BITE          6
#define RBM_STING         7
#define RBM_PECK          8
#define RBM_XXX1          9
#define RBM_BUTT         10
#define RBM_CRUSH        11
#define RBM_ENGULF       12
#define RBM_CRAWL        13
#define RBM_DROOL        14
#define RBM_SPIT         15
#define RBM_SLIME        16
#define RBM_GAZE         17
#define RBM_WAIL         18
#define RBM_SPORE        19
#define RBM_XXX4         20
#define RBM_BEG          21
#define RBM_INSULT       22
#define RBM_XXX5         23
#define RBM_XXX6         24

#define RBE_HURT       1
#define RBE_WOUND      2
#define RBE_BATTER     3
#define RBE_SHATTER    4

#define RBE_UN_BONUS   5
#define RBE_UN_POWER   6
#define RBE_LOSE_MANA  7
#define RBE_EAT_GOLD   8
#define RBE_EAT_ITEM   9
#define RBE_EAT_FOOD  10
#define RBE_EAT_LIGHT 11
#define RBE_HUNGER    12

#define RBE_POISON    13
#define RBE_ACID      14
#define RBE_ELEC      15
#define RBE_FIRE      16
#define RBE_COLD      17

#define RBE_BLIND     18
#define RBE_CONFUSE   19
#define RBE_TERRIFY   20
#define RBE_PARALYZE  21
#define RBE_HALLU     22
#define RBE_DISEASE   23

#define RBE_LOSE_STR  24
#define RBE_LOSE_INT  25
#define RBE_LOSE_WIS  26
#define RBE_LOSE_DEX  27
#define RBE_LOSE_CON  28
#define RBE_LOSE_CHR  29
#define RBE_LOSE_ALL  30

#define RBE_EXP_10    31
#define RBE_EXP_20    32
#define RBE_EXP_40    33
#define RBE_EXP_80    34



/*** Monster flags ***/


/*
 * Special Monster Flags
 */
#define MFLAG_VIEW      	0x00000001L  /* Monster is in line of sight */
#define MFLAG_STERILE		0x00000002L  /* Sterilized Monster */
#define MFLAG_MIMIC  		0x00000004L  /* A mimic detected as an object */
#define MFLAG_ACTV      	0x00000008L  /* Monster is in active mode */
#define MFLAG_HIDE			0x00000010L  /* Monster is hiding in terrain */
#define MFLAG_TOWN      	0x00000020L  /* Monster is using "townsman" AI */
#define MFLAG_SHOW			0x00000040L  /* Monster is recently memorized */
#define MFLAG_MARK			0x00000080L  /* Monster is currently memorized */
#define MFLAG_WARY     	 	0x00000100L  /* Monster is wary (used for traps)*/
#define MFLAG_FLYING       	0x00000200L  /* Monster is flying */
#define MFLAG_TEMP         	0x00000400L  /* Temporary */
#define MFLAG_QUEST			0x00000800L  /* Monster is a quest monster */
#define MFLAG_SLOWER    	0x00001000L  /* Monster is slightly slower than normal */
#define MFLAG_FASTER    	0x00002000L  /* Monster is slightly faster than normal */
#define MFLAG_ALWAYS_CAST	0x00004000L  /* Monster will cast a spell first opportunity */
#define MFLAG_ATTACKED_BAD	0x00008000L  /* Monster has been sneak attacked */
#define MFLAG_AGGRESSIVE	0x00010000L  /* Monster will act aggresively towards the player */
#define MFLAG_HIT_BY_RANGED	0x00020000L  /* Monster has been hit with a spell*/
#define MFLAG_HIT_BY_MELEE	0x00040000L  /* Monster was just meleed by player last turn*/
#define MFLAG_NEED_PASS_WALL_FLOW	0x00080000L  /* Monster needs help getting to the player */
#define MFLAG_QUEST_SUMMON  0x00100000L  /* Monster was summoned by a questor */
#define MFLAG_JUST_SCARED   0x00200000L  /* Monster was scared this turn */
#define MFLAG_BONUS_ITEM    0x00400000L  /* Monster carries a bonus item, for strongholds */
#define MFLAG_DESPERATE		0x00800000L



/*Monster Native Flags*/
#define RN1_N_LAVA		ELEMENT_LAVA/* Native to Lava */
#define RN1_N_ICE		ELEMENT_ICE	/* Native to Ice */
#define RN1_N_OIL		ELEMENT_OIL	/* Native to Oil */
#define RN1_N_FIRE		ELEMENT_FIRE	/* Native to Fire */
#define RN1_N_SAND		ELEMENT_SAND	/* Native to Sand */
#define RN1_N_FOREST	ELEMENT_FOREST	/* Native to Forest */
#define RN1_N_WATER		ELEMENT_WATER	/* Native to Water */
#define RN1_N_ACID		ELEMENT_ACID	/* Native to Acid */
#define RN1_N_MUD		ELEMENT_MUD	/* Native to Mud */
#define RN1_RNXX1_2		0x00000200	/* Unused */
#define RN1_RNXX1_1		0x00000400	/* Unused */
#define RN1_RNXXX_0		0x00000800	/* Unused */
#define RN1_RNXXX_1		0x00001000	/* Unused */
#define RN1_RNXXX_2		0x00002000	/* Unused */
#define RN1_RNXXX_3		0x00004000	/* Unused */
#define RN1_RNXXX_4		0x00008000	/* Unused */
/*other 16 bits unused*/

/*
 * New monster race bit flags
 */
#define RF1_UNIQUE			0x00000001	/* Unique Monster */
#define RF1_QUESTOR			0x00000002	/* Quest Monster */
#define RF1_MALE			0x00000004	/* Male gender */
#define RF1_FEMALE			0x00000008	/* Female gender */
#define RF1_CHAR_CLEAR		0x00000010	/* Absorbs symbol */
#define RF1_CHAR_MIMIC		0x00000020	/* Monster can mimic a symbol */
#define RF1_ATTR_CLEAR		0x00000040	/* Absorbs color */
#define RF1_ATTR_MULTI		0x00000080	/* Changes color */
#define RF1_FORCE_DEPTH		0x00000100	/* Start at "correct" depth */
#define RF1_FORCE_MAXHP		0x00000200	/* Start with max hitpoints */
#define RF1_FORCE_SLEEP		0x00000400	/* Start out sleeping */
#define RF1_FORCE_EXTRA		0x00000800	/* Unused */
#define RF1_FRIEND			0x00001000	/* Arrive with 2-3 friends*/
#define RF1_FRIENDS			0x00002000	/* Arrive with 4-6 friends */
#define RF1_ESCORT			0x00004000	/* Arrive with 4-6 escorts  */
#define RF1_ESCORTS			0x00008000	/* Arrive with 12-18 large escorts  */
#define RF1_NEVER_BLOW		0x00010000	/* Never make physical blow */
#define RF1_NEVER_MOVE		0x00020000	/* Never make physical move */
#define RF1_RAND_25			0x00040000	/* Moves randomly (25%) */
#define RF1_RAND_50			0x00080000	/* Moves randomly (50%) */
#define RF1_ONLY_GOLD		0x00100000	/* Drop only gold */
#define RF1_ONLY_ITEM		0x00200000	/* Drop only items */
#define RF1_DROP_60			0x00400000	/* Drop an item/gold (60%) */
#define RF1_DROP_90			0x00800000	/* Drop an item/gold (90%) */
#define RF1_DROP_1D2		0x01000000	/* Drop 1d2 items/gold */
#define RF1_DROP_2D2		0x02000000	/* Drop 2d2 items/gold */
#define RF1_DROP_3D2		0x04000000	/* Drop 3d2 items/gold */
#define RF1_DROP_4D2		0x08000000	/* Drop 4d2 items/gold */
#define RF1_DROP_GOOD		0x10000000	/* Drop good items */
#define RF1_DROP_GREAT		0x20000000	/* Drop great items */
#define RF1_DROP_CHEST		0x40000000	/* Drop "useful" items */
#define RF1_DROP_CHOSEN		0x80000000	/* Drop "chosen" items */

/*TR1 uber-flags to cover multiple items*/
#define RF1_DROP_UP_TO_10	(RF1_DROP_2D2 | RF1_DROP_3D2)
#define RF1_DROP_UP_TO_12	(RF1_DROP_1D2 | RF1_DROP_2D2 | RF1_DROP_3D2)
#define RF1_DROP_UP_TO_14	(RF1_DROP_4D2 | RF1_DROP_1D2 | RF1_DROP_2D2)
#define RF1_DROP_UP_TO_16	(RF1_DROP_4D2 | RF1_DROP_3D2 | RF1_DROP_1D2)
#define RF1_DROP_UP_TO_18	(RF1_DROP_4D2 | RF1_DROP_3D2 | RF1_DROP_2D2)
#define RF1_DROP_UP_TO_20	(RF1_DROP_4D2 | RF1_DROP_3D2 | RF1_DROP_2D2 | RF1_DROP_1D2)

/*
 * New monster race bit flags
 */
#define RF2_STUPID		0x00000001	/* Monster is stupid */
#define RF2_SMART		0x00000002	/* Monster is smart */
#define RF2_HAS_LIGHT        	0x00000004  	/* Monster carries light */
#define RF2_RF2XXX2		0x00000008	/* (?) */
#define RF2_INVISIBLE		0x00000010	/* Monster avoids vision */
#define RF2_COLD_BLOOD		0x00000020	/* Monster avoids infra */
#define RF2_EMPTY_MIND		0x00000040	/* Monster avoids telepathy.  NOT mindless. */
#define RF2_WEIRD_MIND		0x00000080	/* Monster avoids telepathy sometimes */
#define RF2_MULTIPLY		0x00000100	/* Monster reproduces */
#define RF2_REGENERATE		0x00000200	/* Monster regenerates especially quickly */
#define RF2_RF2XXX4		0x00000400	/* (?) */
#define RF2_EVASIVE		0x00000800	/* Monster often avoids blows */
#define RF2_CLOUD_SURROUND	0x00001000	/* Surrounded by gas/spores/darkness */
#define RF2_RF2XXX5		0x00002000	/* (?) */
#define RF2_PLAYER_GHOST	0x00004000	/* Monster is a player Ghost */
#define RF2_STAY_NATIVE		0x00008000	/* Monster will not leave native terrain */
#define RF2_OPEN_DOOR		0x00010000	/* Monster can open doors */
#define RF2_BASH_DOOR		0x00020000	/* Monster can bash doors */
#define RF2_PASS_WALL		0x00040000	/* Monster can pass walls */
#define RF2_KILL_WALL		0x00080000	/* Monster can destroy walls */
#define RF2_RF2XXX8		0x00100000	/* (?) */
#define RF2_KILL_BODY		0x00200000	/* Monster can kill monsters */
#define RF2_TAKE_ITEM		0x00400000	/* Monster can pick up items */
#define RF2_KILL_ITEM		0x00800000	/* Monster can crush items */
#define RF2_BRAIN_1		0x01000000	/* (?) */
#define RF2_LOW_MANA_RUN    	0x02000000 	/* Runs away/teleports when low on mana */
#define RF2_BRAIN_2         	0x04000000 	/* (?) */
#define RF2_POWERFUL        	0x08000000 	/* Breath loses less power with distance */
#define RF2_RF2XXX1         	0x10000000 	/* Unused */
#define RF2_RF2XXX9		0x20000000 	/* Unused */
#define RF2_RF2XX10      	0x40000000 	/* Unused */
#define RF2_BRAIN_3		0x80000000 	/* (?) */


/*
 * New monster race bit flags
 */
#define RF3_ORC				0x00000001	/* Orc */
#define RF3_TROLL			0x00000002	/* Troll */
#define RF3_GIANT			0x00000004	/* Giant */
#define RF3_DRAGON			0x00000008	/* Dragon */
#define RF3_DEMON			0x00000010	/* Demon */
#define RF3_UNDEAD			0x00000020	/* Undead */
#define RF3_EVIL			0x00000040	/* Evil */
#define RF3_ANIMAL			0x00000080	/* Animal */
#define RF3_FLYING			0x00000100	/* Monster flies */
#define RF3_RF3XXX2			0x00000200	/* (?) */
#define RF3_RF3XXX3			0x00000400	/* Non-Vocal (?) */
#define RF3_RF3XXX4			0x00000800	/* Non-Living (?) */
#define RF3_HURT_LIGHT		0x00001000	/* Hurt by light */
#define RF3_HURT_ROCK		0x00002000	/* Hurt by rock remover */
#define RF3_HURT_FIRE		0x00004000	/* Hurt badly by fire */
#define RF3_HURT_COLD		0x00008000	/* Hurt badly by cold */
#define RF3_IM_ACID			0x00010000	/* Resist acid a lot */
#define RF3_IM_ELEC			0x00020000	/* Resist elec a lot */
#define RF3_IM_FIRE			0x00040000	/* Resist fire a lot */
#define RF3_IM_COLD			0x00080000	/* Resist cold a lot */
#define RF3_IM_POIS			0x00100000	/* Resist poison a lot */
#define RF3_RES_CHAOS		0x00200000	/* Immune to chaos */
#define RF3_RES_NETHR		0x00400000	/* Resist nether a lot */
#define RF3_RES_WATER		0x00800000	/* Resist water, move fast in water  */
#define RF3_RES_PLAS		0x01000000	/* Resist plasma */
#define RF3_RES_NEXUS		0x02000000	/* Resist nexus */
#define RF3_RES_DISEN		0x04000000	/* Resist disenchantment */
#define RF3_NO_SLOW			0x08000000	/* Cannot be slowed */
#define RF3_NO_FEAR			0x10000000	/* Cannot be scared */
#define RF3_NO_STUN			0x20000000	/* Cannot be stunned */
#define RF3_NO_CONF			0x40000000	/* Cannot be confused */
#define RF3_NO_SLEEP		0x80000000	/* Cannot be slept */

/*TR3 uber-flags to cover multiple items*/
#define RF3_IM_ELEM	(RF3_IM_ACID | RF3_IM_ELEC | RF3_IM_FIRE | RF3_IM_COLD | RF3_IM_POIS)
#define RF3_IM_ALL	(RF3_IM_ELEM | RF3_RES_PLAS| RF3_RES_NETHR | RF3_RES_NEXUS | \
					 RF3_RES_DISEN | RF3_RES_CHAOS | RF3_RES_WATER)
#define RF3_NO_CHARM (RF3_NO_FEAR | RF3_NO_STUN | RF3_NO_CONF | RF3_NO_SLEEP | RF3_NO_SLOW)

/*
 * Monster racial flags - innate or physical ranged attacks
 * these spells do not have a failure rate - JG
 * other spells have a chance of failing
 */
#define RF4_SHRIEK         0x00000001  /* Shriek for help */
#define RF4_LASH           0x00000002  /* Use a melee attack at range 2 or 3 */
#define RF4_BOULDER        0x00000004  /* Throw a boulder */
#define RF4_SHOT           0x00000008  /* Fire sling shot */
#define RF4_ARROW          0x00000010  /* Fire arrows */
#define RF4_BOLT           0x00000020  /* Fire crossbow quarrels */
#define RF4_MISSL          0x00000040  /* Fire other physical missiles */
#define RF4_PMISSL         0x00000080  /* Fire poisoned missiles */
#define RF4_BRTH_ACID      0x00000100  /* Breathe Acid */
#define RF4_BRTH_ELEC      0x00000200  /* Breathe Elec */
#define RF4_BRTH_FIRE      0x00000400  /* Breathe Fire */
#define RF4_BRTH_COLD      0x00000800  /* Breathe Cold */
#define RF4_BRTH_POIS      0x00001000  /* Breathe Poison */
#define RF4_BRTH_PLAS      0x00002000  /* Breathe Plasma */
#define RF4_BRTH_LIGHT     0x00004000  /* Breathe Light */
#define RF4_BRTH_DARK      0x00008000  /* Breathe Dark */
#define RF4_BRTH_CONFU     0x00010000  /* Breathe Confusion */
#define RF4_BRTH_SOUND     0x00020000  /* Breathe Sound */
#define RF4_BRTH_SHARD     0x00040000  /* Breathe Shards */
#define RF4_BRTH_INER      0x00080000  /* Breathe Inertia */
#define RF4_BRTH_GRAV      0x00100000  /* Breathe Gravity */
#define RF4_RF4XX1X		   0x00200000  /* Unused */
#define RF4_BRTH_FORCE     0x00400000  /* Breathe Force */
#define RF4_BRTH_NEXUS     0x00800000  /* Breathe Nexus */
#define RF4_BRTH_NETHR     0x01000000  /* Breathe Nether */
#define RF4_BRTH_CHAOS     0x02000000  /* Breathe Chaos */
#define RF4_BRTH_DISEN     0x04000000  /* Breathe Disenchant */
#define RF4_BRTH_TIME      0x08000000  /* Breathe Time */
#define RF4_BRTH_MANA      0x10000000  /* Breathe Mana */
#define RF4_RF4XXX1        0x20000000  /*  */
#define RF4_RF4XXX2        0x40000000  /*  */
#define RF4_RF4XXX3        0x80000000  /*  */


/*uber-flags*/
#define RF4_BRTH_ELEM		(RF4_BRTH_ACID | RF4_BRTH_ELEC | RF4_BRTH_FIRE | \
						 RF4_BRTH_COLD | RF4_BRTH_POIS)
#define RF4_BRTH_POWER	(RF4_BRTH_ELEM | RF4_BRTH_NETHR | RF4_BRTH_LIGHT | RF4_BRTH_DARK | \
						 RF4_BRTH_CONFU | RF4_BRTH_SOUND | RF4_BRTH_CHAOS | RF4_BRTH_DISEN | \
						 RF4_BRTH_NEXUS)
#define RF4_BRTH_ALL	(RF4_BRTH_POWER | RF4_BRTH_TIME | RF4_BRTH_INER | RF4_BRTH_GRAV | \
						 RF4_BRTH_SHARD | RF4_BRTH_PLAS | RF4_BRTH_FORCE | RF4_BRTH_MANA)

/*
 * Monster racial flags - defined-area projection spells
 */
#define RF5_BALL_ACID      0x00000001  /* Acid Ball -> Acid Storm */
#define RF5_BALL_ELEC      0x00000002  /* Elec Ball -> Elec Storm */
#define RF5_BALL_FIRE      0x00000004  /* Fire Ball -> Fire Storm */
#define RF5_BALL_COLD      0x00000008  /* Cold Ball -> Cold Storm */
#define RF5_BALL_POIS      0x00000010  /* Stinking Cloud -> Poison Storm */
#define RF5_BALL_LIGHT     0x00000020  /* Light Ball / Starburst */
#define RF5_BALL_DARK      0x00000040  /* Darkness Ball -> Dark Storm */
#define RF5_BALL_CONFU     0x00000080  /* Confusion Ball -> Conf Storm */
#define RF5_BALL_SOUND     0x00000100  /* Sound Ball -> Sound Storm */
#define RF5_BALL_SHARD     0x00000200  /* Shard Ball -> Shard Storm */
#define RF5_RF5_XXX2       0x00000400  /* Unused */
#define RF5_BALL_STORM     0x00000800  /* Storm Ball -> Tempest */
#define RF5_BALL_NETHR     0x00001000  /* Nether Ball -> Nether Storm */
#define RF5_BALL_CHAOS     0x00002000  /* Chaos Ball -> Chaos Storm */
#define RF5_BALL_MANA      0x00004000  /* Mana Ball -> Mana Storm */
#define RF5_BALL_WATER     0x00008000  /* Water Ball */
#define RF5_BOLT_ACID      0x00010000  /* Acid Bolt */
#define RF5_BOLT_ELEC      0x00020000  /* Elec Bolt */
#define RF5_BOLT_FIRE      0x00040000  /* Fire Bolt */
#define RF5_BOLT_COLD      0x00080000  /* Cold Bolt */
#define RF5_BOLT_POIS      0x00100000  /* Poison Bolt */
#define RF5_BOLT_PLAS      0x00200000  /* Plasma Bolt */
#define RF5_BOLT_ICE       0x00400000  /* Ice Bolt */
#define RF5_BOLT_WATER     0x00800000  /* Water Bolt */
#define RF5_BOLT_NETHR     0x01000000  /* Nether Bolt */
#define RF5_BOLT_MANA      0x02000000  /* Magic Missile -> Mana Bolt */
#define RF5_RF5_XXX3       0x04000000  /* Unused */
#define RF5_BEAM_ELEC      0x08000000  /* Electric spark */
#define RF5_BEAM_ICE       0x10000000  /* Ice Lance */
#define RF5_BEAM_NETHR     0x20000000  /* Spear of Nether */
#define RF5_RF5_XXX4	   0x40000000  /* Unused */
#define RF5_HOLY_ORB       0x80000000  /* Orb of Draining */



/*
 * Monster racial flags - help self, hinder character, and special magics
 */

#define RF6_HASTE          0x00000001  /* Speed self */
#define RF6_ADD_MANA       0x00000002  /* Regain Mana */
#define RF6_HEAL           0x00000004  /* Heal self */
#define RF6_CURE           0x00000008  /* Cure self */
#define RF6_BLINK          0x00000010  /* Teleport Short */
#define RF6_TPORT          0x00000020  /* Teleport Long */
#define RF6_RF6XXX1        0x00000040  /*  */
#define RF6_TELE_SELF_TO   0x00000080  /* Teleport Selt to Player */
#define RF6_TELE_TO        0x00000100  /* Move player to monster */
#define RF6_TELE_AWAY      0x00000200  /* Move player far away */
#define RF6_TELE_LEVEL     0x00000400  /* Move player vertically */
#define RF6_RF6XXX2        0x00000800  /*  */
#define RF6_DARKNESS       0x00001000  /* Create Darkness */
#define RF6_TRAPS          0x00002000  /* Create Traps */
#define RF6_RF6XXX3        0x00004000  /* Unused */
#define RF6_DRAIN_MANA     0x00008000  /* Drain Mana */
#define RF6_RF6XXX4        0x00010000  /*  */
#define RF6_RF6XXX5        0x00020000  /*  */
#define RF6_MIND_BLAST     0x00040000  /* Blast Mind --> Brain Smash */
#define RF6_BRAIN_SMASH    0x00080000  /* */
#define RF6_WOUND          0x00100000  /* Cause Wounds */
#define RF6_RF6XXX6        0x00200000  /*  */
#define RF6_RF6XXX7        0x00400000  /*  */
#define RF6_RF6XXX8        0x00800000  /*  */
#define RF6_RF6XXX9        0x01000000  /*  */
#define RF6_HUNGER         0x02000000  /* Make Player Hungry */
#define RF6_RF6XX11        0x04000000  /*  */
#define RF6_SCARE          0x08000000  /* Frighten Player */
#define RF6_BLIND          0x10000000  /* Blind Player */
#define RF6_CONF           0x20000000  /* Confuse Player */
#define RF6_SLOW           0x40000000  /* Slow Player */
#define RF6_HOLD           0x80000000  /* Paralyze Player */


/*
 * Hack -- Bit masks to control what spells are considered
 * Monster racial flags - summons
 */

#define RF7_S_KIN          0x00000001  /* Summon Similar */
#define RF7_RF7XXX1        0x00000002  /*  */
#define RF7_RF7XXX2        0x00000004  /*  */
#define RF7_S_MONSTER      0x00000008  /* Summon Monster */
#define RF7_S_MONSTERS     0x00000010  /* Summon Monsters */
#define RF7_RF7XXX3        0x00000020  /*  */
#define RF7_RF7XXX4        0x00000040  /*  */
#define RF7_RF7XXX5	       0x00000080  /*  */
#define RF7_S_ANT          0x00000100  /* Summon Ants */
#define RF7_S_SPIDER       0x00000200  /* Summon Spiders */
#define RF7_S_HOUND        0x00000400  /* Summon Hounds */
#define RF7_S_ANIMAL       0x00000800  /* Summon Animals */
#define RF7_S_HYDRA        0x00001000  /* Summon Hydras */
#define RF7_RF7XXX7        0x00002000  /*  */
#define RF7_S_THIEF        0x00004000  /* Summon Thieves */
#define RF7_S_BERTBILLTOM  0x00008000  /* Summon Bert, Bill, and Tom */
#define RF7_RF7XXX8        0x00010000  /* */
#define RF7_S_AINU         0x00020000  /* Summon Ainu */
#define RF7_RF7XX10        0x00040000  /*  */
#define RF7_RF7XX11        0x00080000  /*  */
#define RF7_S_DRAGON       0x00100000  /* Summon Dragon */
#define RF7_S_HI_DRAGON    0x00200000  /* Summon Ancient Dragons */
#define RF7_RF7XX12        0x00400000  /*  */
#define RF7_RF7XX13        0x00800000  /*  */
#define RF7_S_DEMON        0x01000000  /* Summon Demon(s) */
#define RF7_S_HI_DEMON     0x02000000  /* Summon Greater Demons */
#define RF7_RF7XX14        0x04000000  /*  */
#define RF7_S_UNIQUE       0x08000000  /* Summon Unique Monster */
#define RF7_S_HI_UNIQUE    0x10000000  /* Summon High Unique Monster */
#define RF7_S_UNDEAD       0x20000000  /* Summon Undead */
#define RF7_S_HI_UNDEAD    0x40000000  /* Summon Greater Undead */
#define RF7_S_WRAITH       0x80000000  /* Summon Unique Wraith */


 /*
  * Some flags are obvious
  */

#define RF1_OBVIOUS_MASK \
	(RF1_UNIQUE | RF1_QUESTOR | RF1_MALE | RF1_FEMALE | \
	 RF1_FRIEND | RF1_FRIENDS | RF1_ESCORT | RF1_ESCORTS)

/*
 * "race" flags
 */

#define RF3_RACE_MASK \
	(RF3_ORC | RF3_TROLL | RF3_GIANT | RF3_DRAGON | \
	 RF3_DEMON | RF3_UNDEAD | RF3_EVIL | RF3_ANIMAL)

 /*
  * Hack -- Bit masks to control what spells are considered
  */

 /*
  * Attack spells.
  * Need special treatment in movement AI.
  */
#define RF4_BALL_MASK (0L)

#define RF5_BALL_MASK \
	(RF5_BALL_ACID | RF5_BALL_ELEC | RF5_BALL_FIRE | RF5_BALL_COLD | \
	 RF5_BALL_POIS | RF5_BALL_LIGHT | RF5_BALL_DARK | RF5_BALL_CONFU | \
	 RF5_BALL_SOUND | RF5_BALL_SHARD | RF5_BALL_STORM | RF5_BALL_NETHR | \
	 RF5_BALL_CHAOS | RF5_BALL_MANA | RF5_BALL_WATER | RF5_HOLY_ORB)

#define RF6_BALL_MASK (0L)

#define RF7_BALL_MASK (0L)

/*
 * Hack -- "bolt" spells that may hurt fellow monsters
 * Need special treatment in AI.
 */
#define RF4_BOLT_MASK \
        (RF4_ARROW | RF4_BOLT | RF4_SHOT | RF4_MISSL | RF4_PMISSL | RF4_BOULDER)

#define RF5_BOLT_MASK \
	(RF5_BOLT_ACID | RF5_BOLT_ELEC | RF5_BOLT_FIRE | RF5_BOLT_COLD | \
	 RF5_BOLT_POIS | RF5_BOLT_NETHR | RF5_BOLT_WATER | RF5_BOLT_MANA | \
	 RF5_BOLT_PLAS | RF5_BOLT_ICE)

#define RF6_BOLT_MASK \
   0L


#define RF7_BOLT_MASK \
   0L

/*
 * Hack -- "beam" spells that go through fellow monsters
 */
#define RF4_BEAM_MASK   (0L)

#define RF5_BEAM_MASK 	(RF5_BEAM_ELEC | RF5_BEAM_ICE | RF5_BEAM_NETHR)

#define RF6_BEAM_MASK 	(0L)

#define RF7_BEAM_MASK 	(0L)

/*
 * Archery attacks
 * Need special treatment in AI.
  */
#define RF4_ARCHERY_MASK \
        (RF4_ARROW | RF4_BOLT | RF4_SHOT | RF4_MISSL | RF4_PMISSL | RF4_BOULDER)

#define RF5_ARCHERY_MASK 	(0L)

#define RF6_ARCHERY_MASK 	(0L)

#define RF7_ARCHERY_MASK 	(0L)




/*
 * Breath attacks.
 * Need special treatment in movement AI.
 */

#define RF4_ELEM_BREATH_MASK	(RF4_BRTH_ACID | RF4_BRTH_ELEC | RF4_BRTH_FIRE | \
								 RF4_BRTH_COLD | RF4_BRTH_POIS)

#define RF4_BREATH_MASK \
        (RF4_ELEM_BREATH_MASK | RF4_BRTH_PLAS | RF4_BRTH_LIGHT | RF4_BRTH_DARK | \
         RF4_BRTH_CONFU | RF4_BRTH_SOUND | RF4_BRTH_SHARD | RF4_BRTH_INER | \
         RF4_BRTH_GRAV | RF4_BRTH_FORCE | RF4_BRTH_NEXUS | RF4_BRTH_NETHR | \
         RF4_BRTH_CHAOS | RF4_BRTH_DISEN | RF4_BRTH_TIME | RF4_BRTH_MANA)

#define RF5_BREATH_MASK \
 	(0L)

#define RF6_BREATH_MASK \
	(0L)

#define RF7_BREATH_MASK \
	(0L)

 /*
  * Attack spells.
  * Need special treatment in movement AI.
  */
#define RF4_ATTACK_MASK \
        (RF4_ARCHERY_MASK | RF4_BOLT_MASK | RF4_BEAM_MASK | RF4_BALL_MASK)

#define RF5_ATTACK_MASK \
		(RF5_ARCHERY_MASK | RF5_BOLT_MASK | RF5_BEAM_MASK | RF5_BALL_MASK)

#define RF6_ATTACK_MASK \
		(RF6_ARCHERY_MASK | RF6_BOLT_MASK | RF6_BEAM_MASK | RF6_BALL_MASK | \
		RF6_WOUND | RF6_BRAIN_SMASH | RF6_MIND_BLAST)

#define RF7_ATTACK_MASK \
		(RF7_ARCHERY_MASK | RF7_BOLT_MASK | RF7_BEAM_MASK | RF7_BALL_MASK)


/*
 * Harassment (not direct damage) attacks.
 * Need special treatment in AI.
 */
#define RF4_HARASS_MASK \
        (RF4_SHRIEK)

#define RF5_HARASS_MASK \
 	(0L)

#define RF6_HARASS_MASK \
	(RF6_DARKNESS | RF6_TRAPS | RF6_HUNGER | RF6_DRAIN_MANA | \
         RF6_SCARE | RF6_BLIND | RF6_CONF | RF6_SLOW | RF6_HOLD)

#define RF7_HARASS_MASK \
	(0L)


/*
 * Summoning Spells
 * Need special treatment in AI.
  */
#define RF4_SUMMON_MASK \
        (0L)

#define RF5_SUMMON_MASK \
	(0L)

#define RF6_SUMMON_MASK \
	(0L)

#define RF7_SUMMON_MASK \
	(RF7_S_KIN |  RF7_S_MONSTER | RF7_S_MONSTERS | RF7_S_ANT | RF7_S_SPIDER | \
	 RF7_S_HOUND | RF7_S_ANIMAL | RF7_S_HYDRA | RF7_S_THIEF | RF7_S_BERTBILLTOM | \
	 RF7_S_AINU | RF7_S_DRAGON | RF7_S_HI_DRAGON | RF7_S_DEMON | RF7_S_HI_DEMON | \
	 RF7_S_UNIQUE | RF7_S_HI_UNIQUE |  RF7_S_UNDEAD | RF7_S_HI_UNDEAD | RF7_S_WRAITH)


/*
 * Spells that can be can cast without a player in sight
 * Need special treatment in AI.
 */
#define RF4_NO_PLAYER_MASK \
        (0L)

#define RF5_NO_PLAYER_MASK \
        (0L)

#define RF6_NO_PLAYER_MASK \
        (RF6_HEAL | RF6_ADD_MANA | RF6_TELE_SELF_TO | RF6_CURE)

#define RF7_NO_PLAYER_MASK \
        (0L)


/* Spell Desire Table Columns */
#define D_BASE     0
#define D_SUMM     1
#define D_HURT     2
#define D_MANA     3
#define D_ESC      4
#define D_TACT     5
#define D_RES      6
#define D_RANGE    7


/*
 * Monsters will run up to 25 grids away
 */
#define FLEE_RANGE      MAX_SIGHT + 5

/*
 * Hack -- Panicked monsters will run far, far away
 */
#define PANIC_RANGE      100

/* Spell Desire Table Columns */
#define D_BASE     0
#define D_SUMM     1
#define D_HURT     2
#define D_MANA     3
#define D_ESC      4
#define D_TACT     5
#define D_RES      6
#define D_RANGE    7




/*
 * Spells that improve the caster's tactical position
 */
#define RF4_TACTIC_MASK \
	(0L)

#define RF5_TACTIC_MASK \
	(0L)

#define RF6_TACTIC_MASK \
	(RF6_BLINK)


/*
 * Annoying spells
 */
#define RF4_ANNOY_MASK \
	(RF4_SHRIEK)

#define RF5_ANNOY_MASK \
	(RF5_DRAIN_MANA | RF5_SCARE | \
	 RF5_BLIND | RF5_CONF | RF5_SLOW | RF5_HOLD)

#define RF6_ANNOY_MASK \
	(RF6_TELE_TO | RF6_DARKNESS | RF6_TRAPS)


/*
 * Spells that increase the caster's relative speed
 */
#define RF4_HASTE_MASK \
	(0L)

#define RF5_HASTE_MASK \
	(RF5_SLOW | RF5_HOLD)

#define RF6_HASTE_MASK \
	(RF6_HASTE)


/*
 * Healing spells
 */
#define RF4_HEAL_MASK \
	(0L)

#define RF5_HEAL_MASK \
	(0L)

#define RF6_HEAL_MASK \
	(RF6_HEAL)


/*
 * Innate spell-like effects
 */
#define RF4_INNATE_MASK \
	(0L)

#define RF5_INNATE_MASK \
	(0L)

#define RF6_INNATE_MASK \
	(0L)

	/*
 * Monster macros
 */

/*
 * Determine if a given monster is "non-living"
 *
 * Neither demons nor undead are alive.  Neither vortexes nor elementals
 * are alive.  Storms and events are not alive.
 *
 * An chest, wand, rod or staff mimic is assumed to be "animated", and therefore
 * not alive.  All other mimics are "mimics", living creatures that look
 * like something non-living.
 */
#define monster_nonliving(M) \
	(((M)->flags3 & (RF3_DEMON))  || \
	 ((M)->flags3 & (RF3_UNDEAD)) || \
	 (strchr("Evg$+~-_", (M)->d_char)))

#define get_mon_idx(M) \
	(cave_m_idx[(M)->fy][(M)->fx])


/*
 * Determine if the monster is fully visible.
 */
#define mon_fully_visible(M) \
(((M)->ml) && !((M)->mflag & (MFLAG_MIMIC)))

/*
 * Make sure the game doesn't crash if the monster is set to NEED_FLOW
 * and the game calls the flow array.
 */
#define get_monster_flow(M) \
	((M)->using_flow == (NEED_FLOW) ? FLOW_PASS_DOORS	: (M)->using_flow)

/*
 * Will the monster take damage on their current square?
 * Return false if they will take damage, true if they don't take damage
 */
#define cave_no_dam_for_mon(Y, X, M) \
	(is_monster_native(Y, X, M) || \
	f_info[cave_feat[Y][X]].dam_non_native == 0)


/*
 * Returns TRUE if a monster (given its race) can't handle doors and must use the FLOW_*_NO_DOORS flows
 */
#define MONSTER_HATES_DOORS(RACE) \
       (!((RACE)->flags2 & (RF2_OPEN_DOOR | RF2_BASH_DOOR | RF2_PASS_WALL | RF2_KILL_WALL)) && \
       !((RACE)->flags1 & (RF1_NEVER_MOVE)))



/*
 * Return TRUE if the given monster can fly over the given feature
 * NOTE THAT THE MONSTER MUST BE CURRENTLY FLYING
 */
#define MONSTER_CAN_FLY(M_PTR, F_IDX) \
       (((M_PTR)->mflag & (MFLAG_FLYING)) && feat_ff2_match(F_IDX, FF2_CAN_FLY))




/* The codified monster messages */
enum {
	MON_MSG_NONE = 0,

	/* message_pain */
	MON_MSG_UNHARMED,
	MON_MSG_BARELY_NOTICE,
	MON_MSG_FLINCH,
	MON_MSG_SQUELCH,
	MON_MSG_QUIVER,
	MON_MSG_WRITHE_ABOUT,
	MON_MSG_WRITHE_IN_AGONY,
	MON_MSG_JERK,
	MON_MSG_JERK_LIMPLY,
	MON_MSG_JERK_IN_PAIN,
	MON_MSG_JERK_IN_AGONY,
	MON_MSG_JERK_FEEBLY,
	MON_MSG_SHRUG_OFF,
	MON_MSG_SNARL,
	MON_MSG_SNARL_WITH_PAIN,
	MON_MSG_HOWL_IN_PAIN,
	MON_MSG_HOWL_IN_AGONY,
	MON_MSG_YELP_FEEBLY,
	MON_MSG_YELP_IN_PAIN,
	MON_MSG_HISS,
	MON_MSG_HISS_FURIOUSLY,
	MON_MSG_HISS_WITH_PAIN,
	MON_MSG_HISS_IN_AGONY,
	MON_MSG_REAR_UP_IN_ANGER,
	MON_MSG_GROWL_ANGRILY,
	MON_MSG_MEWL_IN_PAIN,
	MON_MSG_MEWL_PITIFULLY,
	MON_MSG_IGNORE_ATTACK,
	MON_MSG_DRONE_ANGRILY,
	MON_MSG_SCUTTLE_ABOUT,
	MON_MSG_TWITCH_IN_PAIN,
	MON_MSG_FLAP_ANGRILY,
	MON_MSG_JEER_IN_PAIN,
	MON_MSG_SQUAWK_WITH_PAIN,
	MON_MSG_TWITTER_IN_AGONY,
	MON_MSG_FLUTTER_ABOUT,
	MON_MSG_CHIRP_FEEBLY,
	MON_MSG_RATTLE,
	MON_MSG_CLATTER,
	MON_MSG_SHAKE,
	MON_MSG_STAGGER,
	MON_MSG_CRUMPLE,
	MON_MSG_GRUNT,
	MON_MSG_GRUNT_WITH_PAIN,
	MON_MSG_MOAN,
	MON_MSG_GROAN,
	MON_MSG_HESITATE,
	MON_MSG_SQUEAL_IN_PAIN,
	MON_MSG_SHRIEK_IN_PAIN,
	MON_MSG_SHRIEK_IN_AGONY,
	MON_MSG_CRY_OUT_FEEBLY,
	MON_MSG_CRY_OUT_IN_PAIN,
	MON_MSG_SCREAM_IN_PAIN,
	MON_MSG_SCREAM_IN_AGONY,
	MON_MSG_STERILIZE,

	/* project_m */
	MON_MSG_DIE,
	MON_MSG_DESTROYED,
	MON_MSG_RESIST_A_LOT,
	MON_MSG_HIT_HARD,
	MON_MSG_RESIST,
	MON_MSG_IMMUNE,
	MON_MSG_RESIST_SOMEWHAT,
	MON_MSG_UNAFFECTED,
	MON_MSG_SPAWN,
	MON_MSG_HEALTHIER,
	MON_MSG_FALL_ASLEEP,
	MON_MSG_WAKES_UP,
	MON_MSG_CRINGE_LIGHT,
	MON_MSG_SHRIVEL_LIGHT,
	MON_MSG_LOSE_SKIN,
	MON_MSG_DISSOLVE,
	MON_MSG_CATCH_FIRE,
	MON_MSG_BADLY_FROZEN,
	MON_MSG_SHUDDER,
	MON_MSG_AWARE_OF_CRAFTY_ABILITIES,
	MON_MSG_AWARE_OF_CUNNING_TACTICS,
	MON_MSG_SENSE_CRAFTY_ABILITIES,
	MON_MSG_SENSE_CUNNING_FOE,
	MON_MSG_CHANGE,
	MON_MSG_DISAPPEAR,
	MON_MSG_MORE_DAZED,
	MON_MSG_DAZED,
	MON_MSG_NOT_DAZED,
	MON_MSG_MORE_CONFUSED,
	MON_MSG_CONFUSED,
	MON_MSG_NOT_CONFUSED,
	MON_MSG_MORE_SLOWED,
	MON_MSG_SLOWED,
	MON_SNG_NOT_SLOWED,
	MON_MSG_MORE_HASTED,
	MON_MSG_HASTED,
	MON_MSG_NOT_HASTED,
	MON_MSG_MORE_AFRAID,
	MON_MSG_FLEE_IN_TERROR,
	MON_MSG_NOT_AFRAID,
	MON_MSG_MORIA_DEATH,
	MON_MSG_DISENTEGRATES,
	MON_MSG_FREEZE_SHATTER,
	MON_MSG_MANA_DRAIN,



	/* Always leave this at the end */
	MAX_MON_MSG
};


/* Maxinum number of stacked monster messages */
#define MAX_STORED_MON_MSG		200
#define MAX_STORED_MON_CODES	400

/*
 * Monster Timed Effects
 */
enum
{
	MON_TMD_SLEEP = 0,
	MON_TMD_STUN,
	MON_TMD_CONF,
	MON_TMD_FEAR,
	MON_TMD_SLOW,
	MON_TMD_FAST,

	MON_TMD_MAX
};

/* Flags for the monster timed functions */

#define MON_TMD_FLG_SEEN		0x0001	/* Monster is seen */
#define MON_TMD_FLG_NOTIFY		0x0002	/* Give notification */
#define MON_TMD_MON_SOURCE		0x0004  /* Monster is causing the damage */
#define MON_TMD_FLG_NOMESSAGE	0x0010  /*  Never show a message */
#define MON_TMD_FLG_NOFAIL		0x0020	/*  Never Fail the Tests. */
/* XXX */

#endif  /* INCLUDED_MONSTER_H */

