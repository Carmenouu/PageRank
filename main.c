#include "pr_etudiants.c"

int main()
{
  FILE *fp;
  SMAT *H;
  VEC  *r;

  fp = fopen( "exemple.dat", "r" );
  H = sm_input( fp );
  fclose( fp );
  sm_output( stdout, H );
  sm_convert(H);
  sm_output( stdout, H );

  r = v_get(H->m);
  for (int i = 0; i < H->m; i++)
  {
  	r->e[i] = 1. / H->m;
  }

  v_output(stdout, r);

  for (int i = 0; i < 100; i++)
  {
  	printf("itération %d:\n", i);
	r = product_vm(r, H);
	v_output(stdout, r);
  }

  sm_free(H);
  v_free(r);

  return 0;
}