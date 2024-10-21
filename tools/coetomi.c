#include <stdio.h>
#include <math.h>
#include <string.h>

#define DEPTH 32768 // 数据深度
#define WIDTH 32 // 数据位宽
								 //
int main(void)
{
	FILE *fp_mi, *fp_coe;
	char *mi_name = "./processing_file/gpio_out_cut_in_right_delay_0116_1111.mi";
	char *coe_name = "./processing_file/gpio_out_cut_in_right_delay_0116_1111.coe";

	char buffer[10] = {0};
	char buffer_end[1] = {0};
	int count = 0;

	fp_mi = fopen(mi_name, "w");
	if (NULL == fp_mi) {
		printf("can not open file %s!\r\n", mi_name);
	} else {
		printf("open file %s successfully!\r\n", mi_name);
		fprintf(fp_mi, "#File_format=Hex\n");
		fprintf(fp_mi, "#Address_depth=%d\n", DEPTH);
		fprintf(fp_mi, "#Data_width=%d\n", WIDTH);
		fp_coe = fopen(coe_name, "r");
		if(NULL == fp_coe)
			printf("can not open file %s!\r\n", coe_name);
	} else {
			printf("open file %s successfully!\r\n", coe_name);
			fseek(fp_coe, 65, 0);
	
			while(fread(buffer, sizeof(char), sizeof(buffer) - 1, fp_coe)) {
				fwrite(buffer, sizeof(char), sizeof(buffer) - 2, fp_mi);

				fread(buffer, sizeof(char), 1, fp_coe);
				fwrite(buffer, sizeof(char), 1, fp_mi);

				memset(buffer, 0, sizeof(buffer));
				count++;
			}

			memset(buffer, '0', sizeof(buffer));
			memset(buffer_end, '\n', 1);

		for(int i = count; i < DEPTH; i++) {
			fwrite(buffer, sizeof(char), sizeof(buffer) - 2, fp_mi);
			fwrite(buffer_end, sizeof(char), 1, fp_mi);
		}

		fclose(fp_coe);
	}

	fclose(fp_mi);
}

