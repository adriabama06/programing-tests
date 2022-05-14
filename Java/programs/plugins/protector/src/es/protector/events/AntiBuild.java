package es.protector.events;

import es.protector.Main;
import es.protector.Util;
import es.protector.config.Config;
import org.bukkit.Location;
import org.bukkit.World;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockBreakEvent;
import org.bukkit.event.block.BlockPlaceEvent;

public class AntiBuild implements Listener {
    private Main plugin;

    public AntiBuild(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public void onBreak(BlockBreakEvent event) {
        Player p = event.getPlayer();
        if(p != null) {
            if(!p.hasPermission("protector.build")) {
                if(!Config.GetProtect().getStringList("enabledlocations").isEmpty()) {
                    for(String areaname : Config.GetProtect().getStringList("enabledlocations")) {
                        if(!Config.GetProtect().getBoolean("locations." + areaname + ".antibuild")) {
                            continue;
                        }
                        double x1 = Config.GetProtect().getDouble("locations." + areaname + ".x1");
                        double y1 = Config.GetProtect().getDouble("locations." + areaname + ".y1");
                        double z1 = Config.GetProtect().getDouble("locations." + areaname + ".z1");

                        double x2 = Config.GetProtect().getDouble("locations." + areaname + ".x2");
                        double y2 = Config.GetProtect().getDouble("locations." + areaname + ".y2");
                        double z2 = Config.GetProtect().getDouble("locations." + areaname + ".z2");

                        World world = plugin.getServer().getWorld(Config.GetProtect().getString("locations." + areaname + ".world"));

                        if(Util.PlayerIsIn(new Location(event.getBlock().getWorld(), event.getBlock().getX(), event.getBlock().getY(), event.getBlock().getZ()), new Location(world, x1, y1, z1), new Location(world, x2, y2, z2))) {
                            event.setCancelled(true);
                            break;
                        }
                    }
                }
            }
        }
    }
    @EventHandler
    public void onPlace(BlockPlaceEvent event) {
        Player p = event.getPlayer();
        if(p != null) {
            if(!p.hasPermission("protector.build")) {
                if(!Config.GetProtect().getStringList("enabledlocations").isEmpty()) {
                    for(String areaname : Config.GetProtect().getStringList("enabledlocations")) {
                        if(!Config.GetProtect().getBoolean("locations." + areaname + ".antibuild")) {
                            continue;
                        }
                        double x1 = Config.GetProtect().getDouble("locations." + areaname + ".x1");
                        double y1 = Config.GetProtect().getDouble("locations." + areaname + ".y1");
                        double z1 = Config.GetProtect().getDouble("locations." + areaname + ".z1");

                        double x2 = Config.GetProtect().getDouble("locations." + areaname + ".x2");
                        double y2 = Config.GetProtect().getDouble("locations." + areaname + ".y2");
                        double z2 = Config.GetProtect().getDouble("locations." + areaname + ".z2");

                        World world = plugin.getServer().getWorld(Config.GetProtect().getString("locations." + areaname + ".world"));

                        if(Util.PlayerIsIn(new Location(world, event.getBlock().getX(), event.getBlock().getY(), event.getBlock().getZ()), new Location(world, x1, y1, z1), new Location(world, x2, y2, z2))) {
                            event.setCancelled(true);
                            break;
                        }
                    }
                }
            }
        }
    }
}
