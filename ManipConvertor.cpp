//g++ ManipConvertor.cpp  $(root-config --glibs --cflags --libs) $(pkg-config  --cflags --libs libfasterac) -o ManipConvertor -O2 -Wall -pthread -std=c++17
#include "../FASTER/NearLine3/NearLine-lib/utils.hpp"
#include "../FASTER/NearLine3/NearLine-lib/Classes/Event.hpp"
#include "../FASTER/NearLine3/NearLine-lib/Classes/FilesManager.hpp"

#include "Classes/Parameters.hpp"
#include "Modules/EachDetector.hpp"


int main(int argc, char ** argv)
{

  Parameters p;
  if (!p.setParameters(argc, argv)) return (-1);
  p.readParameters();

  TChain chain("Nuball");
  std::string rootfile;
  while(p.files().nextFileName(rootfile)) chain.Add(rootfile.c_str());

  Event event(&chain);
  // chain.SetBranchAddress("mult" , &event.mult);
  // chain.SetBranchAddress("label", &event.labels);
  // chain.SetBranchAddress("nrj"  , &event.nrjs);
  // chain.SetBranchAddress("nrj2" , &event.nrj2s);
  // chain.SetBranchAddress("time" , &event.times);

  EachDetector ed;
  ed.setParameters(p.get_ed_setup());

  int nb = chain.GetEntries();
  for (int i = 0; i<nb; i++)
  {
    chain.GetEntry(i);
    ed.Fill(event);
  }

  return 1;
}
