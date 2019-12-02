function onOpenCvReady() {
    cv['onRuntimeInitialized']=()=>{

            var synth = new Tone.Synth().toMaster();
            
            const video = document.getElementById('video');
            const actionBtn = document.getElementById('actionBtn');
            const actionBtnStop = document.getElementById('actionBtn-stop');

            const width = window.innerWidth * 0.75;
            const height = window.innerHeight * 0.75;

            document.getElementById("video").width = width;
            document.getElementById("video").height = height;

            window.innerHeight
            // Increase or decrease this based on the end result for your level of computation
            const FPS = 8;
            let stream;
            let streaming = false;
            let src;
            let dst;
            // Capture video content
            const cap = new cv.VideoCapture(video);
            actionBtn.addEventListener('click', () => {
                if (streaming) {
                    stop();
                    actionBtn.style.display = 'inline';
                    actionBtnStop.style.display = 'none';
                } else {
                    start();
                    actionBtn.style.display = 'none';
                    actionBtnStop.style.display = 'inline';
                }
            });
            actionBtnStop.addEventListener('click', () => {
                if (streaming) {
                    stop();
                    actionBtn.style.display = 'inline';
                    actionBtnStop.style.display = 'none';
                } else {
                    start();
                    actionBtn.style.display = 'none';
                    actionBtnStop.style.display = 'inline';
                }
            });
            // Start video capture...
            function start () {
                navigator.mediaDevices.getUserMedia({ video: true, audio: false })
                .then(_stream => {
                    stream = _stream;
                    console.log('stream', stream);
                    video.srcObject = stream;
                    video.play();
                    streaming = true;
                    src = new cv.Mat(height, width, cv.CV_8UC4);
                    dst = new cv.Mat(height, width, cv.CV_8UC1);
                    setTimeout(processVideo, 0)
                })
                .catch(err => console.log(`An error occurred: ${err}`));
            }
            // Stop video capture...
            function stop () {
                if (video) {
                    video.pause();
                    video.srcObject = null;
                }
                if (stream) {
                    stream.getVideoTracks()[0].stop();
                }
                streaming = false;
            }
            // Process video 
            function processVideo () {
                if (!streaming) {
                    src.delete();
                    dst.delete();
                    return;
                }
                const begin = Date.now();

                let gray = new cv.Mat(height, width, cv.CV_8UC4);
                cap.read(src);

                cv.cvtColor(src, gray, cv.COLOR_RGBA2GRAY);

                let threshold = new cv.Mat(height, width, cv.CV_8UC4);
                cv.threshold(gray,threshold,245,255,cv.THRESH_BINARY)

                // let contours = new cv.MatVector();
                // let hierarchy = new cv.Mat();
                // cv.findContours(threshold, contours, hierarchy, cv.RETR_CCOMP, cv.CHAIN_APPROX_SIMPLE);
                // let cnt = contours.get(0);

                // let circle = cv.minEnclosingCircle(cnt);
                // let contoursColor = new cv.Scalar(255, 255, 255);
                // let circleColor = new cv.Scalar(255, 0, 0);

                // You can try more different parameters

                let erode = new cv.Mat();
                let erodeMat = cv.Mat.ones(7, 7, cv.CV_8U);
                let anchor = new cv.Point(-1, -1);
                // You can try more different parameters
                cv.erode(threshold, erode, erodeMat, anchor, 1, cv.BORDER_CONSTANT, cv.morphologyDefaultBorderValue());

                let M = new cv.Mat();
                let ksize = new cv.Size(10, 10);
                // You can try more different parameters
                M = cv.getStructuringElement(cv.MORPH_ELLIPSE, ksize);
                cv.morphologyEx(erode, dst, cv.MORPH_GRADIENT, M);

                // Circles
                let lines = new cv.Mat();
                cv.Canny(dst, dst, 100, 200, 5);
                
                let contours = new cv.MatVector();
                let hierarchy = new cv.Mat();
                cv.findContours(dst, contours, hierarchy, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE);
                console.log(contours.size());

                // Contour size is given by 2 right now.  So all of them on currently is 18 and then one covered is 16 and so on...

                // Currently we're just playing the C scale but we can change this.
                if(contours.size()==0) {
                    
                }
                // if(contours.size()>0&&contours.size()<=2) {
                //     synth.triggerAttackRelease("C4", "8n");
                // }
                // if(contours.size()>2&&contours.size()<=4) {
                //     synth.triggerAttackRelease("D4", "8n");
                // }
                // if(contours.size()>4&&contours.size()<=6) {
                //     synth.triggerAttackRelease("E4", "8n");
                // }
                // if(contours.size()>6&&contours.size()<=8) {
                //     synth.triggerAttackRelease("F4", "8n");
                // }
                // if(contours.size()>8&&contours.size()<=10) {
                //     synth.triggerAttackRelease("G4", "8n");
                // }
                // if(contours.size()>10&&contours.size()<=12) {
                //     synth.triggerAttackRelease("A4", "8n");
                // }
                // if(contours.size()>12&&contours.size()<=14) {
                //     synth.triggerAttackRelease("B4", "8n");
                // }
                // if(contours.size()>14&&contours.size()<=16) {
                //     synth.triggerAttackRelease("C5", "8n");
                // }
                // if(contours.size()>16&&contours.size()<=18) {
                //     synth.triggerAttackRelease("D5", "8n");
                // }

                if(contours.size()>0&&contours.size()<=4) {
                    synth.triggerAttackRelease("C4", "8n");
                }
                if(contours.size()>4&&contours.size()<=8) {
                    synth.triggerAttackRelease("D4", "8n");
                }
                if(contours.size()>8&&contours.size()<=12) {
                    synth.triggerAttackRelease("E4", "8n");
                }
                if(contours.size()>12&&contours.size()<=16) {
                    synth.triggerAttackRelease("F4", "8n");
                }
                if(contours.size()>16&&contours.size()<=20) {
                    synth.triggerAttackRelease("G4", "8n");
                }
                if(contours.size()>20&&contours.size()<=24) {
                    synth.triggerAttackRelease("A4", "8n");
                }
                if(contours.size()>24&&contours.size()<=28) {
                    synth.triggerAttackRelease("B4", "8n");
                }
                if(contours.size()>28&&contours.size()<=32) {
                    synth.triggerAttackRelease("C5", "8n");
                }
                if(contours.size()>32&&contours.size()<=36) {
                    synth.triggerAttackRelease("D5", "8n");
                }
                // Show whatever you want at the end of it all
                cv.imshow('canvasOutput', dst);

                const delay = 1000/FPS - (Date.now() - begin);
                setTimeout(processVideo, delay);
            }     

    }
}