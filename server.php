<?php

    # access control
    # header("Access-Control-Allow-Origin: *");
    header("Access-Control-Allow-Origin: https://fishyhotel.com");
    header('Content-Type: application/octet-stream');

    # get raw post data
    $pd = file_get_contents("php://input");
    
    # check has valid data
    if(!isset($pd))
    {
        //echo "no data provided";
        header("HTTP/1.1 200 OK");
        exit;
    }

    # store the user data if valid lengths
    if(array_sum(count_chars($pd)) != 31)
    {
        //echo "wrong size";
        header("HTTP/1.1 200 OK");
        exit;
    }

    # generate user unique id
    $id = str_replace('/', '', base64_encode(substr($pd, 0, 4) . pack('N', ip2long($_SERVER['REMOTE_ADDR']))));

    # store user data
    file_put_contents("/dev/shm/fishy/" . $id, $pd, LOCK_EX);

    # remove any timed out users while spitting out an array of users
    $iter = new DirectoryIterator("/dev/shm/fishy/");
    $cnt = 0;
    foreach($iter as $fi)
    {
        if($fi->isDot() || !$fi->isFile()){continue;}
        if($cnt >= 2048){break;} # 2048 max players
        $fn = $fi->getPathname();
        if(time()-filemtime($fn) > 3)
        {
            unlink($fn);
            continue;
        }
        echo file_get_contents($fn);
        $cnt++;
    }

?>
