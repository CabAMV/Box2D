var GameCanvas;
var ctx;


function Update()
{
  Draw();
}

function Draw()
{
  var image=new Image();
  image.src="wood.jpg";
  ctx.clearRect(0,0,GameCanvas.width,GameCanvas.height);
  ctx.fillStyle="black";
  ctx.fillRect(0,0,GameCanvas.width,GameCanvas.height);
  ctx.drawImage(image,(1000/2)-50,400-10,50*2,10*2);
  ctx.drawImage(image,(700/2)-50,350-10,50*2,10*2);
  ctx.drawImage(image,(200/2)-50,300-10,50*2,10*2);
  ctx.drawImage(image,(700/2)-50,250-10,50*2,10*2);

  ctx.drawImage(image,(635/2)-15,200-10,15*2,10*2);
  ctx.drawImage(image,(765/2)-15,200-10,15*2,10*2);
  ctx.drawImage(image,(200/2)-50,200-10,50*2,10*2);
  ctx.drawImage(image,(80/2)-15,175-15,15*2,15*2);
  ctx.drawImage(image,(135/2)-15,150-10,15*2,10*2);
  ctx.drawImage(image,(250/2)-50,100-10,50*2,10*2);
  var secondImage=new Image();
  secondImage.src="Exit.png";
  ctx.drawImage(secondImage,(700/2)-50,50-10,50*2,10*2);




  /*
  createBody(1000,400,50,10,b2Body.b2_staticBody,0,1);
  createBody(700,350,50,10,b2Body.b2_staticBody,0,1);
  createBody(200,300,50,10,b2Body.b2_staticBody,0,1);
  createBody(700,250,50,10,b2Body.b2_staticBody,0,1);

  createBody(635,200,15,10,b2Body.b2_staticBody,0,1);
  createBody(765,200,15,10,b2Body.b2_staticBody,0,1);
  createBody(200,200,50,10,b2Body.b2_staticBody,0,1);
  createBody(80,175,15,15,b2Body.b2_staticBody,0,1);
  createBody(135,150,15,10,b2Body.b2_staticBody,0,1);
  createBody(250,100,50,10,b2Body.b2_staticBody,0,1);
  createBody(700,100,50,10,b2Body.b2_staticBody,0,3);

  */


  paintPlayer();
}

function setCoords(X,Y)
{
  player.X=X;
  player.Y=Y;

}
