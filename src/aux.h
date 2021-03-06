#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include "mat.h"
//#include "video.h"

using namespace std;


void show_video(vector<Matrix> v);
void genByCopy(vector<Matrix>& original_video, vector<Matrix>& new_frames, int frames_toAdd);
void spline_method(vector<Matrix>& original_video, vector<Matrix>& new_frames, int frames_toAdd, int frame_rate, int numberOfFrames, int height, int width);
void linear_interpolation(vector<Matrix>& original_video, vector<Matrix>& new_frames, int frames_toAdd, int frame_rate, int numberOfFrames, int height, int width);
void convert_to_video_and_save(vector<Matrix>& generated_video_frames, string output_file, int frame_rate, int width, int height);
vector<Matrix> load_video(string input_file);

void save_video(string output_file, int numberOfFrames, int height, int width, int frame_rate, int frames_toAdd, vector<int> interval_divider_indexes, vector<vector<Matrix> > & video_by_intervals, vector<vector<Matrix> > & generated_video_by_intervals);
//void save_video(string output_file, int numberOfFrames, int height, int width, int frame_rate, int frames_toAdd, vector<Matrix>& original_video, vector<Matrix>& new_video);

unsigned char evaluate_pol(unsigned char a, double b, double c, double d, double diff_x_xj);
double ECM(Matrix& frame1, Matrix& frame2);
double PSNR(Matrix& frame1, Matrix& frame2);
vector<Matrix> copy_without_some_frames(vector<Matrix>& original_video, int frames_toAdd);
vector<double> ecm_interpolated_vs_original(vector<Matrix>& original_video, vector<Matrix>& new_video, int frames_toAdd);
vector<double> psnr_interpolated_vs_original(vector<Matrix>& original_video, vector<Matrix>& new_video, int frames_toAdd);
vector<Matrix> merge_chunks(vector<vector<Matrix> > & generated_video_by_intervals);


void divide_video_in_intervals(vector<Matrix> & video_frames, vector<vector<Matrix> > & video_by_intervals, vector<int> interval_divider_indexes);
void generate_even_interval_indexes(vector<int> & interval_divider_indexes, int block_size, int numberOfFrames);
void generate_ecm_interval_indexes(vector<Matrix> video_frames, vector<int> & interval_divider_indexes, double threshold);
//Mat convert_to_opencv_frame(Matrix& frame, Size size);