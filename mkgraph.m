
% インポート オプションの設定およびデータのインポート
opts = delimitedTextImportOptions("NumVariables", 9);

% 範囲と区切り記号の指定
opts.DataLines = [2, Inf];
opts.Delimiter = ",";

% 列名と型の指定
opts.VariableNames = ["tod", "ccmtype", "room", "region", "ord", "priority", "ip", "value", "id"];
opts.VariableTypes = ["datetime", "categorical", "double", "double", "double", "double", "categorical", "double", "double"];

% ファイル レベルのプロパティを指定
opts.ExtraColumnsRule = "ignore";
opts.EmptyLineRule = "read";

% 変数プロパティを指定
opts = setvaropts(opts, ["ccmtype", "ip"], "EmptyFieldRule", "auto");
opts = setvaropts(opts, "tod", "InputFormat", "yyyy-MM-dd HH:mm:ss");

% データのインポート
FLOWval = readtimetable("./FLOWval.csv", opts, "RowTimes", "tod");

% 一時変数のクリア
clear opts

% 結果の表示
FLOWval
plot(FLOWval,"tod","value")
