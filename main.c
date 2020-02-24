#include "pr_etudiants.c"

int main()
{
  FILE *fp;
  SMAT *H;
  VEC  *r;

  fp = fopen( "exemple2.dat", "r" );
  H = sm_input( fp );
  fclose( fp );
  sm_output( stdout, H );
  sm_convert(H);
  sm_output( stdout, H );

  r = v_get(3);
  r->e[0] = 1./3;
  r->e[1] = 1./3;
  r->e[2] = 1./3;

  v_output(stdout, r);

  printf("multiplication :\n");
  r = product_vm(r, H);
  v_output(stdout, r);

  return 0;
}