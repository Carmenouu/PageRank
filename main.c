#include "pr_etudiants.c"

int main()
{
  FILE *fp;
  SMAT *SM;

  fp = fopen( "exemple.dat", "r" );
  SM = sm_input( fp );
  fclose( fp );

  sm_output( stdout, SM );

  sm_free( SM );

  return 0;
}