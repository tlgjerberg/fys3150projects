
void write_to_file(string filename, double x, double y, double z, int k) {
  ofstream ofile;
  string filename[dim];
  filename[k] = to_string(k);
  filename[k].append(".txt");
  ofile.open(filename[k], fstream::app);

  // cout << x << " " << y << " " << z << "\n";
  ofile << x << " " << y << " " << z << "\n";
  ofile.close();
}
