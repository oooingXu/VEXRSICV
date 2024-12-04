// This file is Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
// License: BSD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <irq.h>
#include <libbase/uart.h>
#include <libbase/console.h>
#include <generated/csr.h>

/*-----------------------------------------------------------------------*/
/* Uart                                                                  */
/*-----------------------------------------------------------------------*/

static char *readstr(void)
{
	char c[2];
	static char s[64];
	static int ptr = 0;

	if(readchar_nonblock()) {
		c[0] = getchar();
		c[1] = 0;
		switch(c[0]) {
			case 0x7f:
			case 0x08:
				if(ptr > 0) {
					ptr--;
					fputs("\x08 \x08", stdout);
				}
				break;
			case 0x07:
				break;
			case '\r':
			case '\n':
				s[ptr] = 0x00;
				fputs("\n", stdout);
				ptr = 0;
				return s;
			default:
				if(ptr >= (sizeof(s) - 1))
					break;
				fputs(c, stdout);
				s[ptr] = c[0];
				ptr++;
				break;
		}
	}

	return NULL;
}

static char *get_token(char **str)
{
	char *c, *d;

	c = (char *)strchr(*str, ' ');
	if(c == NULL) {
		d = *str;
		*str = *str+strlen(*str);
		return d;
	}
	*c = 0;
	d = *str;
	*str = c+1;
	return d;
}

static void prompt(void)
{
	printf("\e[92;1m先有鸡还是先有蛋\e[0m> ");
}

/*-----------------------------------------------------------------------*/
/* Help                                                                  */
/*-----------------------------------------------------------------------*/

static void help(void)
{
	EGG();
	puts("\nLiteX minimal demo app built "__DATE__" "__TIME__"\n");
	puts("Available commands:");
	puts("\n");
	puts("**********     tools    **********");
	puts("help               - Show this command");
	puts("reboot             - Reboot CPU");
#ifdef CSR_LEDS_BASE
	puts("led                - Led demo");
#endif
	puts("eggs               - EGGS");
	puts("slider             - Slider");
	puts("dry                - Benchmark");
	puts("helloc             - Hello C");
	puts("joytest            - JoyTest");
	puts("time_test          - TimeTest");
	puts("beep               - BeepTest");
	puts("buzzer             - buzzerTest");
	puts("mmrio              - Mario Music");
	puts("clear              - Clear");
	puts("ges_test           - Spinning Donut demo gesture test");
	puts("mputest            - Spinning Donut demo mpu6050 test");
#ifdef WITH_CXX
	puts("hellocpp           - Hello C++");
#endif
	puts("\n");
	puts("**********     Game     **********");
	puts("mario              - Game mario");
//	puts("mariothree         - Game mariothree");
//	puts("hunderd            - Game hunderd");
//	puts("tetris             - Game tetris");
	puts("circus             - Game circus");
	puts("balloon            - Game balloon");
	puts("karateka           - Game karateka");
//	puts("starforce          - Game starforce");
//	puts("stargate           - Game stargate");
//	puts("spartanx           - Game spartanx");
//	puts("skydestroyer       - Game skydestroyer");
	puts("pinball            - Game pinball");
//	puts("pacman             - Game pacman");
//	puts("lunarpool          - Game lunarpool");
//	puts("loderunner         - Game loderunner");
//	puts("exerion            - Game exerion");
//	puts("castlevania        - Game castlevania");
//	puts("bomberman          - Game bomberman");
	puts("kungfu             - Game kungfu");
//	puts("battlecity         - Game battlecity");
	puts("snake              - Game Snake");
	puts("type               - Game type");
//	puts("fone 		 - Game fone");
	puts("pushbox 		 - Game pushbox");
//	puts("block 		 - Game block");
	puts("battle 		 - Game battle");
	puts("moto               - Game moto");
	puts("sevclor            - Game sevclor");
//	puts("mouse              - Game mouse");
//	puts("jmp                - Game jmp");
	puts("skipsquare         - Game skipsquare");
	puts("AE_II              - Game AE_II");
	puts("eattobig           - Game eattobig");
	puts("shake              - Game shake");
	puts("blendoku           - Game blendoku");
	puts("\n");
	puts("**********     Demo     **********");
	puts("cmatrix            - Spinning Donut demo Cmatrix");
	puts("donut              - Spinning Donut demo Donut");
	puts("ant                - Spinning Donut demo Ant");
	puts("video              - Spinning Donut demo Video");
	puts("hanoi              - Spinning Donut demo Hanoi");
}

/*-----------------------------------------------------------------------*/
/* Commands                                                              */
/*-----------------------------------------------------------------------*/

static void reboot_cmd(void)
{
	ctrl_reset_write(1);
}

#ifdef CSR_LEDS_BASE
static void led_cmd(void)
{
	int i;
	printf("Led demo...\n");

	printf("Counter mode...\n");
	for(i=0; i<32; i++) {
		leds_out_write(i);
		busy_wait(100);
	}

	printf("Shift mode...\n");
	for(i=0; i<4; i++) {
		leds_out_write(1<<i);
		busy_wait(200);
	}
	for(i=0; i<4; i++) {
		leds_out_write(1<<(3-i));
		busy_wait(200);
	}

	printf("Dance mode...\n");
	for(i=0; i<4; i++) {
		leds_out_write(0x55);
		busy_wait(200);
		leds_out_write(0xaa);
		busy_wait(200);
	}
}
#endif

extern void snake(void);

static void snake_cmd(void)
{
	printf("Game snake...\n");
	snake();
}
extern void sevclor(void);

static void sevclor_cmd(void)
{
	printf("Game sevclor...\n");
	sevclor();
}
//extern void jmp(void);
//
//static void jmp_cmd(void)
//{
//	printf("Game jmp...\n");
//	jmp();
//}
extern void hanoi(void);

static void hanoi_cmd(void)
{
	printf("Ant demo...\n");
	hanoi();
}

extern void slider(void);

static void slider_cmd(void)
{
	printf("Slider...\n");
	slider();
}

extern void battlecity(void);

static void battlecity_cmd(void)
{
	printf("Game battlecity...\n");
	battlecity();
}

extern void kungfu(void);

static void kungfu_cmd(void)
{
	printf("Game kungfu...\n");
	kungfu();
}

extern void bomberman(void);

static void bomberman_cmd(void)
{
	printf("Game bomberman...\n");
	bomberman();
}

extern void castlevania(void);

static void castlevania_cmd(void)
{
	printf("Game castlevania...\n");
	castlevania();
}

extern void exerion(void);

static void exerion_cmd(void)
{
	printf("Game exerion...\n");
	exerion();
}

extern void loderunner(void);

static void loderunner_cmd(void)
{
	printf("Game loderunner...\n");
	loderunner();
}

extern void lunarpool(void);

static void lunarpool_cmd(void)
{
	printf("Game lunarpool...\n");
	lunarpool();
}

extern void pacman(void);

static void pacman_cmd(void)
{
	printf("Game pacman...\n");
	pacman();
}

extern void pinball(void);

static void pinball_cmd(void)
{
	printf("Game pinball...\n");
	pinball();
}

extern void skydestroyer(void);

static void skydestroyer_cmd(void)
{
	printf("Game skydestroyer...\n");
	skydestroyer();
}

extern void spartanx(void);

static void spartanx_cmd(void)
{
	printf("Game spartanx...\n");
	spartanx();
}

extern void stargate(void);

static void stargate_cmd(void)
{
	printf("Game stargate...\n");
	stargate();
}

extern void starforce(void);

static void starforce_cmd(void)
{
	printf("Game starforce...\n");
	starforce();
}

extern void battle(void);

static void battle_cmd(void)
{
	printf("Game battle...\n");
	battle();
}

extern void block(void);

static void block_cmd(void)
{
	printf("Game block...\n");
	block();
}

extern void pushbox(void);

static void pushbox_cmd(void)
{
	printf("Game pushbox...\n");
	pushbox();
}

extern void fone(void);

static void fone_cmd(void)
{
	printf("Game fone...\n");
	fone();
}

extern void karateka(void);

static void karateka_cmd(void)
{
	printf("Game karateka...\n");
	karateka();
}

extern void balloon(void);

static void balloon_cmd(void)
{
	printf("Game balloon...\n");
	balloon();
}

extern void circus(void);

static void circus_cmd(void)
{
	printf("Game circus...\n");
	circus();
}

extern void hunderd(void);

static void hunderd_cmd(void)
{
	printf("Game hunderd...\n");
	hunderd();
}

extern void joytest(void);

static void joytest_cmd(void)
{
	printf("Game joytest...\n");
	joytest();
}
extern void beep(void);

static void beep_cmd(void)
{
	printf("Game beep...\n");
	beep();
}
extern void buzzer(void);

static void buzzer_cmd(void)
{
	printf("Game buzzer...\n");
	buzzer();
}
extern void mmario(void);

static void mmario_cmd(void)
{
	printf("Game mmario...\n");
	mmario();
}
extern void time_test(void);

static void time_test_cmd(void)
{
	printf("Game time_test...\n");
	time_test();
}

extern void mariothree(void);

static void mariothree_cmd(void)
{
	printf("Game mariothree...\n");
	mariothree();
}

extern void mario(void);

static void mario_cmd(void)
{
	printf("Game mario...\n");
	mario();
}

extern void tetris(void);

static void tetris_cmd(void)
{
	printf("Game tetris...\n");
	tetris();
}

extern void type(void);

static void type_cmd(void)
{
	printf("type...\n");
	type();
}

extern void ant(void);

static void ant_cmd(void)
{
	printf("ant...\n");
	ant();
}

extern void video(void);

static void video_cmd(void)
{
	printf("video...\n");
	video();
}

extern void donut(void);

static void donut_cmd(void)
{
	printf("Donut demo...\n");
	donut();
}

static void clear_cmd(void) {
	printf("\033[H\033[J");
	__am_gpu_init();
}

extern int dry(void);

static void dry_cmd(void)
{
	printf("Benchmark demo...\n");
	dry();
}
extern void cmatrix(void);

static void cmatrix_cmd(void)
{
	printf("Cmatrix demo...\n");
	cmatrix();
}

extern void ges_test(void);

static void ges_test_cmd(void)
{
	printf("Ges_test demo...\n");
	ges_test();
}

extern void mputest(void);

static void mputest_cmd(void)
{
	printf("mputest demo...\n");
	mputest();
}

extern void eggs(void);

static void eggs_cmd(void)
{
	printf("EGGS demo...\n");
	eggs();
}

extern void helloc(void);

static void helloc_cmd(void)
{
	printf("Hello C demo...\n");
	helloc();
}

extern void moto(void);

static void moto_cmd(void)
{
	printf("Hello C demo...\n");
	moto();
}
extern void skipsquare(void);

static void skipsquare_cmd(void)
{
	printf("Hello C demo...\n");
	skipsquare();
}
extern void mouse(void);

static void mouse_cmd(void)
{
	printf("Hello C demo...\n");
	mouse();
}
extern void blendoku(void);

static void blendoku_cmd(void)
{
	printf("Hello C demo...\n");
	blendoku();
}
extern void AE_II(void);

static void AE_II_cmd(void)
{
	printf("Hello C demo...\n");
	AE_II();
}
extern void eattobig(void);

static void eattobig_cmd(void)
{
	printf("Hello C demo...\n");
	eattobig();
}
extern void shake(void);

static void shake_cmd(void)
{
	printf("Hello C demo...\n");
	shake();
}

#ifdef WITH_CXX
extern void hellocpp(void);

static void hellocpp_cmd(void)
{
	printf("Hello C++ demo...\n");
	hellocpp();
}
#endif

/*-----------------------------------------------------------------------*/
/* Console service / Main                                                */
/*-----------------------------------------------------------------------*/

static void console_service(void)
{
	char *str;
	char *token;

	str = readstr();
	if(str == NULL) return;
	token = get_token(&str);
	if(strcmp(token, "help") == 0)
		help();
	else if(strcmp(token, "reboot") == 0)
		reboot_cmd();
#ifdef CSR_LEDS_BASE
	else if(strcmp(token, "led") == 0)
		led_cmd();
#endif
	else if(strcmp(token, "tetris") == 0)
		tetris_cmd();
	else if(strcmp(token, "battlecity") == 0)
		battlecity_cmd();
	else if(strcmp(token, "kungfu") == 0)
		kungfu_cmd();
	else if(strcmp(token, "bomberman") == 0)
		bomberman_cmd();
	else if(strcmp(token, "exerion") == 0)
		exerion_cmd();
	else if(strcmp(token, "pacman") == 0)
		pacman_cmd();
	else if(strcmp(token, "pinball") == 0)
		pinball_cmd();
	else if(strcmp(token, "skydestroyer") == 0)
		skydestroyer_cmd();
	else if(strcmp(token, "spartanx") == 0)
		spartanx_cmd();
	else if(strcmp(token, "starforce") == 0)
		starforce_cmd();
	else if(strcmp(token, "stargate") == 0)
		stargate_cmd();
	else if(strcmp(token, "battle") == 0)
		battle_cmd();
	else if(strcmp(token, "block") == 0)
		block_cmd();
	else if(strcmp(token, "pushbox") == 0)
		pushbox_cmd();
	else if(strcmp(token, "fone") == 0)
		fone_cmd();
	else if(strcmp(token, "lunarpool") == 0)
		lunarpool_cmd();
	else if(strcmp(token, "loderunner") == 0)
		loderunner_cmd();
	else if(strcmp(token, "karateka") == 0)
		karateka_cmd();
	else if(strcmp(token, "balloon") == 0)
		balloon_cmd();
	else if(strcmp(token, "castlevania") == 0)
		castlevania_cmd();
	else if(strcmp(token, "circus") == 0)
		circus_cmd();
	else if(strcmp(token, "hunderd") == 0)
		hunderd_cmd();
	else if(strcmp(token, "joytest") == 0)
		joytest_cmd();
	else if(strcmp(token, "beep") == 0)
		beep_cmd();
	else if(strcmp(token, "buzzer") == 0)
		buzzer_cmd();
	else if(strcmp(token, "mmario") == 0)
		mmario_cmd();
	else if(strcmp(token, "time_test") == 0)
		time_test_cmd();
	else if(strcmp(token, "mariothree") == 0)
		mariothree_cmd();
	else if(strcmp(token, "mario") == 0)
		mario_cmd();
	else if(strcmp(token, "snake") == 0)
		snake_cmd();
	else if(strcmp(token, "sevclor") == 0)
		sevclor_cmd();
//	else if(strcmp(token, "jmp") == 0)
//		jmp_cmd();
	else if(strcmp(token, "slider") == 0)
		slider_cmd();
	else if(strcmp(token, "cmatrix") == 0)
		cmatrix_cmd();
	else if(strcmp(token, "ges_test") == 0)
		ges_test_cmd();
	else if(strcmp(token, "mputest") == 0)
		mputest_cmd();
	else if(strcmp(token, "type") == 0)
		type_cmd();
	else if(strcmp(token, "ant") == 0)
		ant_cmd();
	else if(strcmp(token, "video") == 0)
		video_cmd();
	else if(strcmp(token, "donut") == 0)
		donut_cmd();
	else if(strcmp(token, "hanoi") == 0)
		hanoi_cmd();
	else if(strcmp(token, "dry") == 0)
		dry_cmd();
	else if(strcmp(token, "eggs") == 0)
		eggs_cmd();
	else if(strcmp(token, "clear") == 0)
		clear_cmd();
	else if(strcmp(token, "helloc") == 0)
		helloc_cmd();
	else if(strcmp(token, "moto") == 0)
		moto_cmd();
	else if(strcmp(token, "mouse") == 0)
		mouse_cmd();
	else if(strcmp(token, "skipsquare") == 0)
		skipsquare_cmd();
	else if(strcmp(token, "blendoku") == 0)
		blendoku_cmd();
	else if(strcmp(token, "AE_II") == 0)
		AE_II_cmd();
	else if(strcmp(token, "eattobig") == 0)
		eattobig_cmd();
	else if(strcmp(token, "shake") == 0)
		shake_cmd();
#ifdef WITH_CXX
	else if(strcmp(token, "hellocpp") == 0)
		hellocpp_cmd();
#endif
	prompt();
}

int main(void)
{
#ifdef CONFIG_CPU_HAS_INTERRUPT
	irq_setmask(0);
	irq_setie(1);
#endif
	uart_init();
	//ioe_init();
	__am_gpu_init();

	help();
	prompt();

	while(1) {
		console_service();
	}

	return 0;
}
