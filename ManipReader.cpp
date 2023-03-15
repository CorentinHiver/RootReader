#ifndef MANIPREADER_H
#define MANIPREADER_H

class ManipReader
{
public:
  ManipReader();
  void setListRuns(std::vector const & file = "Parameters/list_runs.list")
private:
  std::vector<std::string> list_runs;
}

ManipReader::ManipReader()
{

}

#endif //MANIPREADER_H
